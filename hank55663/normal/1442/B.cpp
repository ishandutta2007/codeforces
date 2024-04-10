#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int front[200005],back[200005];
void solve(){   
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    int loc[200005];
    int used[200005];
    fill(used,used+n+1,0);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        front[i]=i-1;
        back[i]=i+1;
        loc[a[i]]=i;
    }
    int b[200005];
    for(int i = 1;i<=k;i++){
        scanf("%d",&b[i]);
        used[b[i]]=1;
    }
    LL ans=1;
    int mod=998244353;
    for(int i = 1;i<=k;i++){
        int aa=loc[b[i]];
        int fr=front[aa];
        int ba=back[aa];
        int pro=2;
        if(fr==0||used[a[fr]])pro--;
        if(ba==n+1||used[a[ba]])pro--;
        ans*=pro;
        ans%=mod;
        back[fr]=ba;
        front[ba]=fr;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/