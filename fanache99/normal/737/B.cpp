//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

char s[1 + MAXN];
vector<pair<int, int> > parts;

int main() {
    int n, a, b, k, limit = 0, length = 0;
    cin >> n >> a >> b >> k;
    cin >> s + 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            length++;
        else {
            if (length >= b) {
                parts.push_back(make_pair(length, i - length));
                limit += length / b;
            }
            length = 0;
        }
    if (length >= b) {
        parts.push_back(make_pair(length, n + 1 - length));
        limit += length / b;
    }
    cout << limit - a + 1 << "\n";
    int x = limit - a + 1;
    for (auto &it : parts) {
        int here = it.first / b;
        for (int i = 1; i <= here; i++) {
            cout << it.second + b * i - 1 << " ";
            x--;
            if (!x)
                return 0;
        }
    }
    return  0;
}