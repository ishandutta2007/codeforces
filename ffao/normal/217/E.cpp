#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#include <ext/rope>
using namespace __gnu_cxx;

char s[3100000];
int k, n;
pii qs[5100];
int t[5100];

void solve()
{
    scanf("%s", s);
    re(k,n);

    rep(i,0,n) re(qs[i].first, qs[i].second);

    int tot = k;
    for (int i = n-1; i >= 0; i--) {
        t[i] = tot;
        int st = qs[i].second, ed = qs[i].second + (qs[i].second-qs[i].first);
        ed = min(tot-1, ed);
        if (ed < st) continue;

        tot -= max(0, ed - st + 1);
    }

    rope<char> ro;
    ro.insert(0, s, s+tot);
    
    // printf("%s\n",ro.c_str());
    for (int q = 0; q < n; q++) {
        int l = qs[q].first-1, r = qs[q].second-1;
        int dst = r+1;
        
        int hm = 0;
        for (int i = l+1; i <= r && dst < t[q]; i += 2) {
            s[hm++]=ro[i];
            dst++;
        }
        for (int i = l; i <= r && dst < t[q]; i += 2) {
            s[hm++] = ro[i];
            dst++;
        }
        s[hm]='\0';
        ro.insert(r+1,s);

        // printf("%s\n",ro.c_str());
    }

    printf("%s\n", ro.c_str());
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}