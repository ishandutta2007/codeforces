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
#define index Index
const int mod=1e9+7;
pii p[1000005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,m,a,b,c,d,pp;
    int x=1,y=1;
    scanf("%d %d %d %d %d %d %d",&n,&m,&a,&b,&c,&d,&pp);
    LL succ=pp*f_pow(100,mod-2)%mod,asucc=(100-pp)*f_pow(100,mod-2)%mod;
    vector<pii> v;
    int nowx=a,nowy=b;
    if(nowx+x>n)x=x*-1;
    if(nowy+y>m)y=y*-1;
    int stx=x,sty=y;
    do{
        v.pb(mp(nowx,nowy));
        nowx+=x;
        nowy+=y;
        if(nowx+x>=1&&nowx+x<=n);
        else x=x*-1;
        if(nowy+y>=1&&nowy+y<=m);
        else y=y*-1;
      //  printf("%d %d %d %d\n",nowx,nowy,x,y);
      //  getchar();
    }while(nowx!=a||nowy!=b||x!=stx||y!=sty);
    v.pb(mp(nowx,nowy));
   // printf("%lld\n",asucc);
    reverse(v.begin(),v.end());
    p[0]=mp(1,0);
    for(int i = 1;i<v.size();i++){
        if(v[i].x!=c&&v[i].y!=d){
            p[i]=p[i-1];
            p[i].y++;
        }
        else{
            p[i]=p[i-1];
            p[i].y++;
            p[i].x=p[i].x*asucc%mod;
            p[i].y=p[i].y*asucc%mod;
        }
    }
    auto ans=p[v.size()-1];
  //  for(auto it:v)printf("%d %d\n",it.x,it.y);
   // for(int i = 0;i<v.size();i++)printf("%d %d\n",p[i].x,p[i].y);
    printf("%lld\n",ans.y*f_pow((1-ans.x+mod)%mod,mod-2)%mod);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/