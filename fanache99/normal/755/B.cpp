//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

map<string, bool> seen;

int main() {
    int n, m, p = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        seen[a] = true;
    }
    for (int i = 1; i <= m; i++) {
        string b;
        cin >> b;
        if (seen[b])
            p++;
    }
    n -= p;
    m -= p;
    if (p % 2)
        if (n >= m)
            cout << "YES\n";
        else
            cout << "NO\n";
    else
        if (n <= m)
            cout << "NO\n";
        else
            cout << "YES\n";
    return 0;
}