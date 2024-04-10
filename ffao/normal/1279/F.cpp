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


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


int n, k, l, sm, bg;
char s[1000010];
pair<int, int> dp[1000010];

pair<int, int> check(int pen, bool lower) {
    memset(dp,-1,sizeof(dp));

    dp[n] = {0,0};
    for (int i = n-1; i >= 0; i--) {
        bool is_lower = (s[i] >= 'a' && s[i] <= 'z');
        if (!lower) is_lower = !is_lower;

        dp[i] = dp[i+1];
        dp[i].first += is_lower;

        int tgt = min(n,i+l);
        pair<int, int> use = dp[tgt];
        use.first += (tgt-i) - pen;
        use.second--;
        dp[i] = max(dp[i],use);
    }

    return dp[0];
}

void solve()
{
    re(n, k, l);
    scanf("%s", s);

    sm = 0, bg = n;
    while (sm < bg) {
        int md = (sm+bg)/2;
        pair<int,int> c = check(md,true);
        //printf("%d true -> %d %d\n", md, c.first, c.second);
        if (-check(md, true).second > k) sm = md+1;
        else bg = md; 
    }
    pair<int,int> t = check(sm,true);
    int ans = t.first + (sm * k);

    sm = 0, bg = n;
    while (sm < bg) {
        int md = (sm+bg)/2;
        if (-check(md, false).second > k) sm = md+1;
        else bg = md; 
    }
    t = check(sm,false);
    int ans2 = t.first + (k * sm);

    printf("%d\n", n-max(ans,ans2));
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}