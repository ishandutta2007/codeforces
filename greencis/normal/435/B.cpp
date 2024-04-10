#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

string s;
int k;
char z[9];

int main()
{
    cin >> s >> k;
    for (int i = 0; i < s.size(); ++i) {
        char mx = 0;
        int mxi = 0;
        for (int j = 1; j <= k && i+j < s.size(); ++j) {
            if (s[i+j] > mx) {
                mx = s[i+j];
                mxi = j;
            }
        }
        if (mx > s[i]) {
            s.erase(i+mxi,1);
            *z = mx;
            s.insert(i, z);
            k -= mxi;
        }
    }
    cout << s;
    return 0;
}