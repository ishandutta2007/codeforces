#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<pll> v[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL pro,in,da;
    scanf("%lld %lld %lld",&pro,&in,&da);
    LL r[100005];
    for(int i =1;i<=n;i++){
        LL m,s;
        scanf("%lld %lld %lld",&m,&s,&r[i]);
        if(da>=m){
            if(in!=0){
                printf("-1\n");
                return 0;
            }
            else{
                r[i]=0;
            }
        }
        v[i].pb(mp(0,s));
    }
    for(int i = 0;i<m;i++){
        int ti;
        LL en,he;
        scanf("%d %lld %lld",&ti,&en,&he);
        v[en].pb(mp(ti,he));
    }
    vector<pll> vv;
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        for(int j = 0;j<v[i].size();j++){
            if(v[i][j].y<=da){
                LL x;
                if(r[i]!=0)
                x=(da-v[i][j].y)/r[i];
                else
                x = 1e18; 
                LL l = v[i][j].x,r=v[i][j].x+x+1;
                if(j!=v[i].size()-1){
                    r=min(r,(LL)v[i][j+1].x);
                }
                if(r>=1e18&&in!=0){
                    printf("-1\n");
                    return 0;
                }
                vv.pb(mp(l,1));
                vv.pb(mp(r,-1));
            }
        }
    }
    LL sum=0;
    LL ans = 0;
    sort(vv.begin(),vv.end());
    for(auto it:vv){
        ans=max(ans,sum*(pro+in*(it.x-1)));
        sum+=it.y;
    }
    printf("%lld\n",ans);
}