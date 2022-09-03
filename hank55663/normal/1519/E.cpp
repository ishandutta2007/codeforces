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
#define last Last
#define MAXK 2500
vector<pii> v[400005];
int vis[400005];
vector<pii> ans;
int instk[400005];
bool dfs(int x,int f){
    vis[x]=1;
    instk[x]=1;
    vector<int> vv;
    for(auto it:v[x]){
        if(it.y!=f){
            if(!vis[it.x]){
                if(!dfs(it.x,it.y)){
                    vv.pb(it.y);
                }
            }
            else if(instk[it.x]){
                vv.pb(it.y);
            }
        }
    }
    if(f!=0)
    vv.pb(f);
      instk[x]=0;
    if(vv.size()%2==0){
        for(int i = 0;i<vv.size();i+=2){
            ans.pb(mp(vv[i],vv[i+1]));
        }
        return true;
    }
    else{
        for(int i = 0;i+1<vv.size();i+=2){
            ans.pb(mp(vv[i],vv[i+1]));
        }
        //if(f!=0)
        //ans.pb(mp(vv[0],f));
         // instk[x]=0;
        return false;
    }
  
}
void solve(){
    int n;
    scanf("%d",&n);
    map<pll,int> m;
    pair<pll,pll> p[200005];
    for(int i = 0;i<n;i++){
        LL a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        //p[i]=mp(mp(a,b),mp(c,d));
        pll p1=mp((a+b)*d,c*b);
        pll p2=mp(a*d,(c+d)*b);
        LL gcd=__gcd(p1.x,p1.y);
        p1.x/=gcd;
        p1.y/=gcd;
        gcd=__gcd(p2.x,p2.y);
        p2.x/=gcd;
        p2.y/=gcd;
        p[i]=mp(p1,p2);
        m[p1];
        m[p2];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    for(int i = 0;i<n;i++){
        v[m[p[i].x]].pb(mp(m[p[i].y],i+1));
        v[m[p[i].y]].pb(mp(m[p[i].x],i+1));
      //  printf("%d %d\n",m[p[i].x],m[p[i].y]);
    }
    for(int i = 1;i<=index;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
    int t=1;00000;
//    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
*/