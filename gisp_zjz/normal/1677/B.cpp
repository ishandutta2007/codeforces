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
char s[maxn];
bool vis[maxn];
int a[maxn],b[maxn],n,m,_,p[maxn],sum[maxn];
void solve(){
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for (int i=0;i<m;i++) vis[i]=0;
    for (int i=0;i<n*m;i++) a[i]=b[i]=0;
    for (int i=0;i<n*m;i++) if (s[i]=='1'&&!vis[i%m]) vis[i%m]=1,a[i]++;
    for (int i=0;i<n;i++) a[i*m]++;
    for (int i=0;i<n*m;i++) sum[i+1]=sum[i]+(s[i]=='1');
    for (int i=1;i<=n*m;i++) if (sum[i]==sum[max(0,i-m)]) b[i-1]++;
    for (int i=1;i<n*m;i++) a[i]+=a[i-1];
    for (int i=m;i<n*m;i++) b[i]+=b[i-m];
    for (int i=0;i<n*m;i++) printf("%d ",a[i]-b[i]);puts("");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}