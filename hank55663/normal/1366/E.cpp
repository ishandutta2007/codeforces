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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    vector<pii> v;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(!v.empty()&&v.back().x>=x)v.pop_back();
        v.pb(mp(x,i));
    }
    int now=0;
    LL ans=1;
    int mod=998244353;
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        if(i==0&&v[now].x!=x)ans=0;
        while(now!=v.size()&&v[now].x!=x)now++;
        if(now==v.size()){
            ans=0;
        }
        else{
            if(i){
                ans*=v[now].y-v[now-1].y;
                ans%=mod;
                now++;
            }
        }
    }
    printf("%lld\n",ans);
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/