//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXL = 20;

unordered_map<string, int> table;
int dad[1 + 2 * MAXN], h[1 + 2 * MAXN];

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        h[i] = 1;
    }
}

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

void Join(int a, int b) {
    if (h[a] < h[b])
        dad[a] = b;
    else {
        dad[b] = a;
        if (h[a] == h[b])
            h[b]++;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        table[s] = i;
    }
    Initialize(2 * n);
    for (int i = 1; i <= m; i++) {
        int type, x, y;
        string a, b;
        cin >> type >> a >> b;
        x = table[a];
        y = table[b];
        if (type == 1)
            if (FindDad(x) == FindDad(y + n))
                cout << "NO\n";
            else {
                cout << "YES\n";
                Join(FindDad(x), FindDad(y));
                Join(FindDad(x + n), FindDad(y + n));
            }
        else
            if (FindDad(x) == FindDad(y))
                cout << "NO\n";
            else {
                cout << "YES\n";
                Join(FindDad(x), FindDad(y + n));
                Join(FindDad(x + n), FindDad(y));
            }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        string a, b;
        cin >> a >> b;
        x = table[a];
        y = table[b];
        if (FindDad(x) == FindDad(y))
            cout << "1\n";
        else
            if (FindDad(x) == FindDad(y + n))
                cout << "2\n";
            else
                cout << "3\n";
    }
    return 0;
}