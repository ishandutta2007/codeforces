#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=2e5+10;
const int M=998244353;
ll a[maxn],b[maxn][18];
int ans,n,_,d[maxn];
ll qry(int l,int r){
    if (r<l) return 0;
    int x=d[r-l+1];
    return __gcd(b[l][x],b[r-(1<<x)+1][x]);
}
void solve(){
    ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]); --n;
    for (int i=1;i<=n;i++) b[i][0]=abs(a[i]-a[i+1]);
    for (int j=1;j<18;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            b[i][j]=__gcd(b[i][j-1],b[i+(1<<(j-1))][j-1]);
    int r=1;
    for (int l=1;l<=n;l++){
        while (r<=n&&qry(l,r)!=1) ++r;
        ans=max(ans,r-l);
    }
    printf("%d\n",ans+1);
}
int main(){
    d[1]=0; for (int i=2;i<maxn;i++) d[i]=d[i/2]+1;
    scanf("%d",&_);
    while (_--) solve();
}