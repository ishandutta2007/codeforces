#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int n, ans = 0;
    scanf("%d", &n);
    while (n--) {
        string s;
        cin >> s;
        ans += mp[s];
    }
    printf("%d\n", ans);
    return 0;
}