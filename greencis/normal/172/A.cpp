#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s[30005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; ; ++i) {
        bool good = true;
        for (int j = 0; j < n-1; ++j) {
            if (s[j].substr(0,i+1) != s[j+1].substr(0,i+1)) {
                good = false;
                break;
            }
        }
        if (!good) { cout << i; return 0; }
    }
    return 0;
}