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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<pii,int> > v;
    int rans=0;
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v.pb(mp(mp(x,y),w));
    }  
    for(int i = 29;i>=0;i--){
        for(int i = 1;i<=n;i++)f[i]=i;
        rans+=(1<<i);
        int tot=0;
        for(auto it:v){
            if(it.y&rans);
            else{
                int a=Find(it.x.x),b=Find(it.x.y);
                if(a!=b)tot++;
                f[a]=b;
            }
        }
        if(tot!=n-1)rans-=(1<<i);
    }
    printf("%d\n",(1<<30)-rans-1);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}