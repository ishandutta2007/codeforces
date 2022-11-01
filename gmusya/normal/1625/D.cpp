#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int k;
vector<int> ans;
vector<int> arr;

struct Trie {
    int root;
    int tail;
    vector<int> l, r;
    vector<int> index;

    explicit Trie() {
        root = 1;
        tail = 2;
        l.assign(2, 0);
        r.assign(2, 0);
        index.assign(2, -1);
    }

    int new_node() {
        l.push_back(0);
        r.push_back(0);
        index.push_back(-1);
        return tail++;
    }

    void add(int value, int pos) {
        int node = root;
        for (int pow = (1 << 29); pow >= 1; pow >>= 1) {
            if (value & pow) {
                if (!r[node]) {
                    r[node] = new_node();
                }
                node = r[node];
            } else {
                if (!l[node]) {
                    l[node] = new_node();
                }
                node = l[node];
            }
        }
        index[node] = pos;
    }

    int get(int value) {
        int node = root;
        for (int pow = (1 << 29); pow >= 1; pow >>= 1) {
            if (value & pow) {
                if (!l[node]) {
                    node = r[node];
                } else {
                    node = l[node];
                }
            } else {
                if (!r[node]) {
                    node = l[node];
                } else {
                    node = r[node];
                }
            }
        }
        return index[node];
    }
};

int solve(vector<int>& tmp, int pow = (1 << 29)) {
    if (tmp.empty()) {
        return 0;
    }
    if (tmp.size() == 1) {
        ans.push_back(tmp[0]);
        return 1;
    }
    if (pow >= k) {
        vector<int> one, zero;
        for (int ind : tmp) {
            if (arr[ind] & pow) {
                one.push_back(ind);
            } else {
                zero.push_back(ind);
            }
        }
        return solve(zero, pow / 2) + solve(one, pow / 2);
    } else {
        Trie trie{};
        for (int ind : tmp) {
            trie.add(arr[ind], ind);
        }
        for (int ind : tmp) {
            int pos = trie.get(arr[ind]);
            if ((arr[ind] ^ arr[pos]) >= k) {
                ans.push_back(ind);
                ans.push_back(pos);
                return 2;
            }
        }
        ans.push_back(tmp[0]);
        return 1;
    }
}

int main() {
    int n;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    if (k == 0) {
        cout << n << '\n';
        for (int ind : p) {
            cout << ind + 1 << ' ';
        }
        return 0;
    }
    solve(p);
    if (ans.size() < 2) {
        cout << -1;
    } else {
        cout << ans.size() << '\n';
        for (int ind : ans) {
            cout << ind + 1 << ' ';
        }
    }
    return 0;
}