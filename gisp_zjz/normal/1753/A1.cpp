#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,a[maxn],m,ans[maxn],pos[maxn],cnt;
void solve(){
    cin >> n; m=0; cnt=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) if (a[i]!=0) pos[++m]=i;
    pos[m+1]=n+1;
    if (m%2){puts("-1");return;}
    if (pos[1]!=1) ans[++cnt]=1;
    for (int i=1;i<=m;i+=2){
        int x=pos[i],y=pos[i+1];
        if ((y-x)&1){
            if (a[x]==a[y]){
                ans[++cnt]=x;
            } else {
                ans[++cnt]=x;
                ans[++cnt]=y;
            }
        } else {
            if (a[x]!=a[y]){
                ans[++cnt]=x;
            } else {
                ans[++cnt]=x;
                ans[++cnt]=y-1;
            }
        }
    }
    ans[cnt+1]=n+1;
    printf("%d\n",cnt);
    for (int i=1;i<=cnt;i++) printf("%d %d\n",ans[i],ans[i+1]-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}