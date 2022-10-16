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

int v[1 + MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for (int i = 3; i <= n; i++)
        if (v[i - 2] + v[i - 1] > v[i]) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}