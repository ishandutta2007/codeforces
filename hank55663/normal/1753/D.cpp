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
vector<pii> v[300005];
vector<string> s;
int X[4]={0,0,1,-1},Y[4]={1,-1,0,0};
LL dis[300005];
void solve(){
    int n,m,p,q;
    scanf("%d %d %d %d",&n,&m,&p,&q);
    //q=min(q,2*p);
    for(int i = 0;i<n;i++){
        char c[300005];
        scanf("%s",c);
        s.pb(string(c));
    }
    vector<int> root;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(s[i][j]=='.')root.pb(i*m+j);
            else if(s[i][j]!='#'){
                if(s[i][j]=='L'){
                    if(j!=0&&s[i][j-1]!='#'){
                        v[i*m+j-1].pb(mp(i*m+j+1,q));
                    }
                    if(i!=0&&s[i-1][j]!='#'){
                        v[(i-1)*m+j].pb(mp(i*m+j+1,p));
                    }
                    if(i!=n-1&&s[i+1][j]!='#'){
                         v[(i+1)*m+j].pb(mp(i*m+j+1,p));
                    }
                }
                if(s[i][j]=='R'){
                    if(j!=m-1&&s[i][j+1]!='#'){
                        v[i*m+j+1].pb(mp(i*m+j-1,q));
                    }
                    if(i!=0&&s[i-1][j]!='#'){
                        v[(i-1)*m+j].pb(mp(i*m+j-1,p));
                    }
                    if(i!=n-1&&s[i+1][j]!='#'){
                         v[(i+1)*m+j].pb(mp(i*m+j-1,p));
                    }
                }
                if(s[i][j]=='U'){
                    if(i!=0&&s[i-1][j]!='#'){
                        v[(i-1)*m+j].pb(mp((i+1)*m+j,q));
                    }
                    if(j!=0&&s[i][j-1]!='#'){
                        v[i*m+j-1].pb(mp((i+1)*m+j,p));
                    }
                    if(j!=m-1&&s[i][j+1]!='#'){
                        v[i*m+j+1].pb(mp((i+1)*m+j,p));
                    }
                }
                 if(s[i][j]=='D'){
                    if(i!=n-1&&s[i+1][j]!='#'){
                        v[(i+1)*m+j].pb(mp((i-1)*m+j,q));
                    }
                    if(j!=0&&s[i][j-1]!='#'){
                        v[i*m+j-1].pb(mp((i-1)*m+j,p));
                    }
                    if(j!=m-1&&s[i][j+1]!='#'){
                        v[i*m+j+1].pb(mp((i-1)*m+j,p));
                    }
                }
            }
        }
    }
    MEMS(dis);
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    for(auto it:root)pq.push(mp(0,it));
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        if(dis[p.y]!=-1)continue;
        dis[p.y]=p.x;
        for(auto it:v[p.y]){
            if(dis[it.x]==-1){
                pq.push(mp(dis[p.y]+it.y,it.x));
            }
        }
    }
  //  for(int i = 0;i<n;i++){
    //    for(int j = 0;j<m;j++){
         //   printf("%lld ",dis[i*m+j]);
      //  }
      //  printf("\n");
  //  }
    LL ans=1e18;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(s[i][j]!='#'){
                for(int k = 0;k<4;k++){
                    int x=X[k]+i,y=Y[k]+j;
                    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='#'){
                        LL a=dis[i*m+j],b=dis[x*m+y];
                        if(a>=0&&b>=0){
                            ans=min(ans,a+b);
                        }
                    }
                }
            }
        }
    }
    if(ans==1e18)ans=-1;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}