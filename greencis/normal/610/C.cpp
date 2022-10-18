#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,k,len;
char s[2105][2105],p[2105][2105],t[2105];

int main()
{
    cin >> k;
    n = 1 << k;
    s[0][0] = '+';
    len = 1;
    for (int i = 0; i < k; ++i, len *= 2) {
        for (int y = 0; y < len; ++y)
            for (int x = 0; x < len; ++x)
                p[y][x+x] = p[y][x+x+1] = s[y][x];
        for (int y = 0; y < len; ++y)
            for (int x = 0; x < len+len; ++x)
                s[y][x] = p[y][x];
        for (int y = 0; y < len; ++y) {
            for (int x = 0; x < len; ++x) {
                if (s[y][x+x] == '+')
                    s[y+len][x+x] = '+', s[y+len][x+x+1] = '*';
                else
                    s[y+len][x+x] = '*', s[y+len][x+x+1] = '+';
            }
        }
    }

    for (int i = 0; i < n; ++i)
        puts(s[i]);

    return 0;
}