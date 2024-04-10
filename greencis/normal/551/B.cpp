#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

char a[100105],b[100105],c[100105];
char d[100105];
int di;
int al,bl,cl;
int ac[26],bc[26],cc[26];
int mx,mx_b,mx_c;

int main()
{
    cin >> a >> b >> c;
    al = strlen(a);
    bl = strlen(b);
    cl = strlen(c);
    for (int i = 0; i < al; ++i) ++ac[a[i] - 97];
    for (int i = 0; i < bl; ++i) ++bc[b[i] - 97];
    for (int i = 0; i < cl; ++i) ++cc[c[i] - 97];

    int mxb = 2e9;
    for (int i = 0; i < 26; ++i)
        if (bc[i]) mxb = min(mxb, ac[i] / bc[i]);
    for (int i = 0; i <= mxb; ++i) {
        int cntc = 2e9;
        for (int j = 0; j < 26; ++j)
            if (cc[j]) cntc = min(cntc, (ac[j] - i * bc[j]) / cc[j]);
        if (i+cntc > mx) {
            mx = i+cntc;
            mx_b = i;
            mx_c = cntc;
        }
    }
    for (int i = 0; i < mx_b; ++i) cout << b;
    for (int i = 0; i < mx_c; ++i) cout << c;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < ac[i] - mx_b * bc[i] - mx_c * cc[i]; ++j)
            d[di++] = 'a' + i;
    }
    d[di] = 0;
    cout << d;

    return 0;
}