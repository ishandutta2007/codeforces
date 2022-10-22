#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> leaf_children(N, 0);
    vector<bool> leaf(N, true);
    vector<int> parent(N);
   
    for (int i = 1; i < N; ++i) {
        cin >> parent[i];
        --parent[i];
        leaf[parent[i]] = false;
    }

    for (int i = 0; i < N; ++i)
        if (leaf[i])
            leaf_children[parent[i]]++;

    bool ok = true;
    for (int i = 0; i < N; ++i)
        if (!leaf[i])
            if (leaf_children[i] < 3)
                ok = false;
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
}