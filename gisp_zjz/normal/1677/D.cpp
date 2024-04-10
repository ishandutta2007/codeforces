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
int _,n,k,p[maxn];
void solve(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    for (int i=n-k;i<n;i++) if (p[i]!=0&&p[i]!=-1){puts("0");return;}
    int ans=1;
    for (int i=1;i<=k;i++) ans=1ll*ans*i%M;
    for (int i=0;i<n-k;i++){
        if (p[i]==0) ans=1ll*ans*(k+1)%M;
        else if (p[i]==-1) ans=1ll*ans*(k+i+1)%M;
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}