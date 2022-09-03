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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int r[200005],c[200005];
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    vector<pii> v;
    int x=0,y=0;
    v.pb(mp(x,y));
    int Maxx=0,Maxy=0;
    map<int,int> xx,yy;
    xx[0]=0;
    yy[0]=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='D')x++;
        else y++;
        v.pb(mp(x,y));
        Maxx=max(Maxx,x);
        Maxy=max(Maxy,y);
        xx[x]=y;
        yy[y]=x;
     //   printf("%d %d\n",x,y);
    }
  //  for(auto it:xx)printf("!%d %d\n",it.x,it.y);
    LL ans=n*1ll*n;
    if(c[0]=='R'){
        for(auto it:xx){
            ans-=Maxy-it.y;
        }
        int ok=0;
        int x=0,y=0;
        for(int i = 0;c[i]!=0;i++){
              if(c[i]=='D')x++;
                else y++;
            if(c[i]=='R'&&!ok)ans-=(n-1);
            
            if(c[i]=='D'){
                ok=1;
            }
             if(ok)ans-=Maxx-yy[y],yy[y]=Maxx;
        }
        if(!ok)ans=n;
    }
    else{
        for(auto it:yy){
            ans-=Maxx-it.y;
        }
      //  printf("%lld\n",ans);
        int ok=0;
         int x=0,y=0;
        for(int i = 0;c[i]!=0;i++){
             if(c[i]=='D')x++;
                else y++;
            if(c[i]=='D'&&!ok)ans-=(n-1);
      
            if(c[i]=='R') ok=1;
                  if(ok)ans-=Maxy-xx[x],xx[x]=Maxy;
           //  printf("%lld\n",ans);

        }
        if(!ok)ans=n;
    }
    printf("%lld\n",ans);

}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}