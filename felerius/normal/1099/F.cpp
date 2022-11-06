#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <set>
#include <vector>


#define CODEFORCES_VERSION

using namespace std;

struct Treap {
    constexpr static auto NEG_INF = numeric_limits<int>::min();
    constexpr static auto POS_INF = numeric_limits<int>::max();
    static uniform_int_distribution<int> PRIO_DIST;
    static mt19937 RNG;

    Treap* left = nullptr;
    Treap* right = nullptr;

    int prio;
    uint32_t secrets;
    uint32_t hack_duration;
    uint64_t total_secrets;
    uint64_t total_duration;

    Treap(uint32_t secrets, uint32_t hack_duration)
            : prio{PRIO_DIST(RNG)}, secrets{secrets},
              hack_duration{hack_duration}, total_secrets{secrets},
              total_duration{total_self_duration()} {}

    uint64_t total_self_duration() const {
        return static_cast<uint64_t>(secrets) * hack_duration;
    }

    Treap* rotate_left() {
        auto* new_root = right;
        assert(new_root != nullptr);

        new_root->total_secrets = total_secrets;
        new_root->total_duration = total_duration;

        right = new_root->left;
        new_root->left = this;

        total_secrets = secrets +
                        (left == nullptr ? 0 : left->total_secrets) +
                        (right == nullptr ? 0 : right->total_secrets);
        total_duration = total_self_duration() +
                         (left == nullptr ? 0 : left->total_duration) +
                         (right == nullptr ? 0 : right->total_duration);

        return new_root;
    }

    Treap* rotate_right() {
        auto* new_root = left;
        assert(new_root != nullptr);

        new_root->total_secrets = total_secrets;
        new_root->total_duration = total_duration;

        left = new_root->right;
        new_root->right = this;

        total_secrets = secrets +
                        (left == nullptr ? 0 : left->total_secrets) +
                        (right == nullptr ? 0 : right->total_secrets);
        total_duration = total_self_duration() +
                         (left == nullptr ? 0 : left->total_duration) +
                         (right == nullptr ? 0 : right->total_duration);

        return new_root;
    }

    Treap* insert(Treap* node) {
        total_secrets += node->secrets;
        total_duration += node->total_self_duration();

        auto** side = node->hack_duration <= hack_duration ? &left : &right;
        if (*side == nullptr) {
            *side = node;
        } else {
            *side = (*side)->insert(node);
        }

        if ((*side)->prio > prio) {
            if (side == &left) {
                return rotate_right();
            } else {
                return rotate_left();
            }
        }

        return this;
    }

    Treap* remove(Treap* node) {
        if (node != this) {
            total_secrets -= node->secrets;
            total_duration -= node->total_self_duration();
            if (node->hack_duration > hack_duration) {
                right = right->remove(node);
            } else {
                left = left->remove(node);
            }

            return this;
        }

        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else if (left->prio <= right->prio) {
            auto* new_root = rotate_left();
            new_root->left = remove(this);
            new_root->total_secrets -= secrets;
            new_root->total_duration -= total_self_duration();
            return new_root;
        } else {
            auto* new_root = rotate_right();
            new_root->total_secrets -= secrets;
            new_root->total_duration -= total_self_duration();
            new_root->right = remove(this);
            return new_root;
        }
    }

    pair<uint64_t, uint64_t> count_secrets(uint64_t time) const {
        if (time >= total_duration) {
            return {total_secrets, total_duration};
        }

        auto rem_time = time;
        uint64_t num_secrets = 0;
        if (left != nullptr) {
            auto[left_secrets, left_time] = left->count_secrets(rem_time);
            num_secrets += left_secrets;
            rem_time -= left_time;
        }

        if (rem_time < hack_duration) {
            return {num_secrets, time};
        }

        if (rem_time <= total_self_duration()) {
            return {num_secrets + rem_time / hack_duration, time};
        }

        num_secrets += secrets;
        rem_time -= total_self_duration();

        if (right != nullptr) {
            auto[right_secrets, right_time] = right->count_secrets(rem_time);
            num_secrets += right_secrets;
            rem_time -= right_time;
        }

        return {num_secrets, time - rem_time};
    }
};

uniform_int_distribution<int> Treap::PRIO_DIST{NEG_INF + 1, POS_INF - 1};
mt19937 Treap::RNG{random_device{}()};

uint64_t dp(size_t node_id, uint64_t rem_time,
            const vector<vector<pair<size_t, uint32_t>>>& childs,
            const vector<pair<uint32_t, uint32_t>>& servers, Treap** treap) {
    auto node = Treap{servers[node_id].first, servers[node_id].second};
    if (*treap == nullptr) {
        *treap = &node;
    } else {
        *treap = (*treap)->insert(&node);
    }

    auto self_secrets = (*treap)->count_secrets(rem_time).first;

#ifdef CODEFORCES_VERSION
    if (node_id != 0 && childs[node_id].size() < 2) {
#else
    if (childs[node_id].size() < 2) {
#endif
        *treap = (*treap)->remove(&node);
        return self_secrets;
    }

    array<uint64_t, 2> best = {0, 0};
    for (auto [child, hack_time] : childs[node_id]) {
        if (2 * hack_time > rem_time) {
            continue;
        }

        auto child_secrets = dp(child, rem_time - 2 * hack_time, childs, servers,
                                treap);
        if (child_secrets > best[0]) {
            best = {child_secrets, best[0]};
        } else if (child_secrets > best[1]) {
            best[1] = child_secrets;
        }
    }

    *treap = (*treap)->remove(&node);

#ifdef CODEFORCES_VERSION
    if (node_id == 0) {
        return max(self_secrets, best[0]);
    }
#endif

    return max(self_secrets, best[1]);
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    uint64_t time;
    cin >> n >> time;

    vector<pair<uint32_t, uint32_t>> servers(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> servers[i].first;
    }
    for (size_t i = 0; i < n; ++i) {
        cin >> servers[i].second;
    }

    vector<vector<pair<size_t, uint32_t>>> childs(n);
    for (size_t i = 1; i < n; ++i) {
        size_t parent;
        uint32_t hack_time;
        cin >> parent >> hack_time;
        childs[parent - 1].emplace_back(i, hack_time);
    }

    Treap* treap = nullptr;
    auto secrets = dp(0, time, childs, servers, &treap);

    cout << secrets << '\n';

    return 0;
}