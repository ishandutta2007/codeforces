#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> factor[2000005];
pll p[200005];
pll pre[200005];
bool cmp(const pii &p,const pii &q){
    return p.y/p.x<q.y/q.x;
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005],b[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
    p[1]=mp(1,0);
    vector<pll> tmp;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        pii ttmp=p[i];
        ttmp.x*=-1;
        ttmp.y*=-1;
        if(i!=1)
        ttmp.y+=a[i]-b[i];
        for(int j = i*2;j<=n;j+=i){
            p[j].x+=ttmp.x;
            p[j].y+=ttmp.y;
        }
        p[i]=ttmp;
        if(p[i].x){
            if(p[i].x<0)p[i].x*=-1,p[i].y*=-1;
            tmp.pb(p[i]);
        }
        else ans+=abs(p[i].y);
   //     printf("%d %d\n",p[i].x,p[i].y);
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i = 0;i<tmp.size();i++)p[i+1]=tmp[i];
    for(int i = 1;i<=tmp.size();i++){
        pre[i]=pre[i-1];
        pre[i].x+=p[i].x;
        pre[i].y+=p[i].y;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        x-=a[1];
       // printf("%d\n",x);
        int Min=0,Max=tmp.size()+1;
        while(Min+1<Max){
            int mid=(Max+Min)/2;
            if(p[mid].x*x+p[mid].y>=0)Max=mid;
            else Min=mid;
        }
        pll a=pre[Min],b=pre[tmp.size()];
        b.x-=a.x;
        b.y-=a.y;
       // printf("%d %d %d %d %d\n",a.x,a.y,b.x,b.y,Min);
        printf("%lld\n",-a.x*x-a.y+b.x*x+b.y+ans);
    }
}

int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/