
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,T,a,b;
        scanf("%d %d %d %d",&n,&T,&a,&b);
        int h[200005];
        LL tot[2]={0,0};
        for(int i = 0;i<n;i++){
            scanf("%d",&h[i]);
            tot[h[i]]++;
        }
        map<int,vector<int> > m;
        for(int i = 0;i<n;i++){
            int ti;
            scanf("%d",&ti);
            m[ti].pb(h[i]);
        }
        m[T+1];
        LL cnt[2]={0,0};
        LL ans=0;
        for(auto it:m){
            LL ti=it.x-1;
            if(cnt[0]*a+cnt[1]*b<=ti){
                ti-=cnt[0]*a+cnt[1]*b;
                LL le[2]={tot[0]-cnt[0],tot[1]-cnt[1]};
                int Minx=min(le[0],ti/a);
                ti-=Minx*a;
                int Miny=min(le[1],ti/b);
                ti-=Miny*b;
                ans=max(ans,cnt[0]+cnt[1]+Minx+Miny);
            }
            for(auto it2:it.y)
                cnt[it2]++;
        }
        printf("%lld\n",ans);
    }
}