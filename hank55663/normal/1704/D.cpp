#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<LL> v;
    LL Max=0;
    for(int i = 0;i<n;i++){
        LL ans=0;
        for(int j = 0;j<m;j++){
            LL x;
            scanf("%lld",&x);
            ans+=x*j;
        }
        v.pb(ans);
        Max=max(Max,ans);
    }
    for(int i = 0;i<v.size();i++){
        if(v[i]==Max){
            printf("%d %lld\n",i+1,Max-min(v[0],v.back()));
            return;
        }
    }
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/