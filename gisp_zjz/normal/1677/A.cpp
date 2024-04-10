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
int _,n,a[5050],s[5050];
void solve(){
    scanf("%d",&n); ans=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        int tot=0;
        for (int j=1;j<i;j++) s[a[j]]++;
        for (int j=1;j<=n;j++) s[j]+=s[j-1];
        for (int j=n;j>i;j--){
            ans+=tot*s[a[j]];
            if (a[j]<a[i]) ++tot;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}