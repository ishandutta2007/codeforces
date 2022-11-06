#include <bits/stdc++.h>

// Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
// Problem: F: Gardener Alex (https://codeforces.com/contest/1220/problem/F)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

struct Node {
    int idx;
    Node *left = nullptr, *right = nullptr;
};

int depth(Node* v) {
    if (!v)
        return 0;
    return max(depth(v->left), depth(v->right)) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    auto it = min_element(begin(a), end(a));
    int orig_shift = (n - (it - begin(a))) % n;
    rotate(begin(a), it, end(a));

    int left = 0, right = n;
    vector<int> b(n);
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i)
        nodes[i].idx = i;
    vector<Node*> stack;
    int mind = n;
    while (right - left > 1) {
        for (auto& node : nodes)
            node.left = node.right = nullptr;
        stack.clear();

        int mid = (left + right) / 2;

        int start = (n - mid) % n;
        for (int i = start; i < n + start; ++i) {
            Node* left = nullptr;
            while (!stack.empty() && a[stack.back()->idx] > a[i % n]) {
                left = stack.back();
                stack.pop_back();
            }

            if (!stack.empty())
                stack.back()->right = &nodes[i % n];
            if (right)
                nodes[i % n].left = left;
            stack.push_back(&nodes[i % n]);
        }

        Node* root = stack.front();
        auto ldepth = depth(root->left);
        auto rdepth = depth(root->right);
        mind = min(mind, max(ldepth, rdepth) + 1);
        if (ldepth == rdepth) {
            cout << (ldepth + 1) << ' ' << ((n - mid - orig_shift + n) % n) << '\n';
            return 0;
        } else if (ldepth > rdepth) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << mind << ' ' << ((n - left - orig_shift + n) % n) << '\n';
    return 0;
}