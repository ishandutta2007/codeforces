#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;


bool dfs(size_t node, const vector<vector<size_t>>& childs,
         const vector<bool>& respectless, vector<size_t>& respectless_list) {
    bool r = respectless[node];
    for (auto c : childs[node]) {
        bool d = dfs(c, childs, respectless, respectless_list);
        r &= d;
    }

    if (r) {
        respectless_list.emplace_back(node);
    }

    return respectless[node];
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    size_t root = 0;
    vector<vector<size_t>> childs(n);
    vector<bool> respectless(n);
    for (size_t i = 0; i < n; ++i) {
        int parent;
        bool d;
        cin >> parent >> d;
        respectless[i] = d;
        if (parent == -1) {
            root = i;
        } else {
            childs[parent - 1].emplace_back(i);
        }
    }

    vector<size_t> respectless_list;
    dfs(root, childs, respectless, respectless_list);
    sort(respectless_list.begin(), respectless_list.end());
    if (respectless_list.empty()) {
        cout << "-1\n";
    } else {
        for (auto i : respectless_list) {
            cout << (i + 1) << " ";
        }
        cout<<'\n';
    }

    return 0;
}