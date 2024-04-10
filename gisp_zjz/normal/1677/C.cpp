#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int> vi;
const int inf=2e9+9;
const int maxn=1e6+10;
const int M=998244353;
ll ans;
bool vis[maxn];
int _,n,a[maxn],b[maxn],p[maxn];
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++) p[a[i]]=i,vis[i]=0;
    int sum=0;
    for (int i=1;i<=n;i++) if (!vis[i]){
        int cnt=1,x=p[b[i]];
        vis[i]=1;
        while (x!=i){
            vis[x]=1; x=p[b[x]];
            ++cnt;
        }
        sum+=cnt/2;
    }
    ans=0;
    for (int i=1;i<=sum;i++){
        int x=i,y=n+1-i;
        ans+=2ll*(y-x);
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}