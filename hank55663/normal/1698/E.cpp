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
#define double long double
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005],b[200005];
    fill(b+1,b+n+1,-1);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    int vis[200005];
    fill(vis,vis+n+1,0);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x!=-1)b[x]=i,vis[i]=1;
    }
    set<int> s;
    int tot=0;
    LL ans=1;
    const int mod=998244353;
    for(int i = 1;i<=k;i++){
        if(vis[a[i]])s.insert(a[i]);
        else tot++;
    }
    for(int i = 1;i<=n;i++){
        if(i+k<=n){
            if(vis[a[i+k]])s.insert(a[i+k]);
            else tot++;
        }
        if(b[i]==-1)ans=ans*tot%mod,tot--;
        else{
            if(s.find(b[i])==s.end())ans=0;
            else s.erase(b[i]);
        }
    }
    printf("%lld\n",ans);


}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/