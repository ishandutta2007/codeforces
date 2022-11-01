#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;
char g[51][51];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    memset(g, '=', sizeof g);
    vector<int> atleast;

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
        if(a[i] == 2) atleast.push_back(i);
        g[i][i] = 'X';
    }
    

    if(atleast.size() == 1 || atleast.size() == 2) puts("NO");
    else {
        for(int i = 0; i < (int)atleast.size(); i++) {
            int j = (i + 1) % (int)atleast.size();
            g[atleast[i]][atleast[j]] = '+';
            g[atleast[j]][atleast[i]] = '-';
        }
        puts("YES");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) printf("%c", g[i][j]);
            puts("");
        }
    }
    if(--t) goto st;
    return 0;
}