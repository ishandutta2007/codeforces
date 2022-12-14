#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> l;
    string name;
    cin >> name;
    for (auto& i : name)
        l.insert(i);
    
    cout << (l.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");

    return 0;
}