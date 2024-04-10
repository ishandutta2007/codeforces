#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s,names[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < 8; ++i) {
        if (names[i].size() == n) {
            bool good = true;
            for (int j = 0; j < n; ++j) {
                if (s[j] != '.' && s[j] != names[i][j]) good = false;
            }
            if (good) { cout << names[i]; return 0; }
        }
    }

    return 0;
}