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
#define N 262144
LL a[200005];
LL pre[200005];
LL pre2[200005];
LL suf[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+a[i];
      //  pre2[i]=pre2[i-1]+pre[i];
    }
    for(int i = n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }
    for(int i =1;i<=n;i++){
        pre2[i]=pre2[i-1]+suf[i];
    }
    LL ans=0;
   /* for(int i = 0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,pre2[j]-pre[n]*j+j*pre[j]
                       -i*pre[j]
                       +i*pre[n]-pre2[i]);
           // printf("%d %d %d %d\n",i,j,pre2[j]-pre[n]*j+j*pre[j]+i*pre[n]-i*pre[j]-pre2[i],pre2[j]-pre2[i]-(j-i)*(pre[n]-pre[j]));
        }
    }*/
    vector<pair<LL,pll> > v;
    v.pb(mp(-1e18,mp(0,0)));
    for(int j=1;j<=n;j++){
        auto it=*(upper_bound(v.begin(),v.end(),mp(-pre[j],mp(-1000000000000000000ll,-1000000000000000000ll)))-1);
        ans=max(ans,it.y.x*-pre[j]+it.y.y+pre2[j]-pre[n]*j+j*pre[j]);
        LL x;
        LL a=j,b=j*pre[n]-pre2[j];
        while(true){
            auto p=v.back();
            v.pop_back();
            x=(p.y.y-b)/(a-p.y.x);
            /*if(p.y.y-b<0){
                x--;
            }*/
            if(p.x>x)continue;
            else{
                v.pb(p);
                break;
            }
        }   
        v.pb(mp(x,mp(a,b)));
    }
    printf("%lld\n",ans);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/