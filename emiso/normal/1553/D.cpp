#include <bits/stdc++.h>

#define MN 1001000

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

ll t, n, ans, a[MN];
char s[MN]; string str, pat;
vector<int> occ[2][26];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%s", &s); str = s;
    scanf("%s", &s); pat = s;

    for(int i = 0; i < 26; i++) {
        occ[0][i].clear();
        occ[1][i].clear();
    }

    for(int i = 0; i < str.size(); i++) {
        occ[i%2][str[i]-'a'].push_back(i);
    }

    for(int par = 0; par < 2; par++) {
        int l = 0;
        for(int i = 0, j = par; l < pat.size(); j = 1-j, l++) {
            auto tt = lower_bound(occ[j][pat[l]-'a'].begin(), occ[j][pat[l]-'a'].end(), i);
            if(tt == occ[j][pat[l]-'a'].end()) break;
            i = (*tt) + 1;
        }
        ans |= (l == pat.size() && (str.size() % 2 == (par + pat.size()) % 2));
    }

    puts(ans ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}