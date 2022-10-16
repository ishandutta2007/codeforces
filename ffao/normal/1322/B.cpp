#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


#include <tuple>


void re(int& x);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n;
int cnt[21000000];
int s[21000000];

void solve()
{
    int ans = 0;

    re(n);
    rep(i,0,n) {
        int t; re(t);
        cnt[t]++;
        for (int x = t; x > 0; x -= x&-x) s[x] ^= 1;
        if (!(n&1)) ans ^= t;
    }

    for (int p = 24; p >= 1; p--) {
        int t = 0;
        int ll = std::min(10000001, (1<<p));
        int cnt_h = 0;

        for (int k = (1<<(p-1)); k < ll; k++ ) {
            cnt_h ^= cnt[k];
            int qq = 0, lim = (1<<p) - k;
            //printf("k=%d lim=%d\n",k,lim);
            for (int x = lim; x <= 10000000; x+=x&-x) qq ^= s[x];
            qq ^= cnt_h;

            t += ((cnt[k]&1) & (qq&1));
            //printf("k=%d cnt=%d qq=%d\n",k,cnt[k],qq);
            if (lim <= k) t += ((cnt[k]*1ll*(cnt[k]-1))/2)&1;
        }
        for (int k = (1<<(p-1)); k < (1<<p); k++) if (cnt[k]) {
            int pp = k ^ (1<<(p-1));
            //printf("k=%d -> %d\n",k,pp);
            for (int x = pp; x > 0; x -= x&-x) s[x] ^= (cnt[k]&1);
            for (int x = k; x > 0; x -= x&-x) s[x] ^= (cnt[k]&1);
            cnt[pp]+=cnt[k];
        }
        t=(t%2)+2;
        //printf("p=%d t=%d\n",p,t);
        ans ^= ( (1<<p) * (t&1) );
    }

    ps(ans);
}


int main() {


    solve();
}


 // and triples


void re(int& x) { scanf("%d", &x); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


#include <array>