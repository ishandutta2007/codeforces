
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    //int t;
    //scanf("%d",&t);
    //while(t--){
    LL n;
    scanf("%lld",&n);
    vector<vector<int> > v;
    int cnt[1000005];
    fill(cnt,cnt+1000005,0);
    for(int i = 0;i<n;i++){
        int k;
        scanf("%d",&k);
        vector<int> tmp;
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
            cnt[x]++;
        }
        v.pb(tmp);
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        LL tot=0;
        for(auto it:v[i]){
            tot+=cnt[it];
            tot%=mod;
        }
        ans+=tot*f_pow(n*v[i].size()%mod*n%mod,mod-2);
        ans%=mod;
    }
    printf("%lld\n",ans);
    //}
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/