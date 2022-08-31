#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+10;
const int inf=1e9+10;
int a[maxn],b[maxn],n,k,m,_;

int main(){
    cin >> _;
    while (_--){
        cin >> n >> m >> k;
        k=min(k,m-1);
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=m;i++) b[i]=max(a[i],a[n-m+i]);
        int ans=0;
        for (int i=0;i<=k;i++){
            int res=inf;
            for (int j=1+i;j<=m-(k-i);j++) res=min(res,b[j]);
            ans=max(ans,res);
        }
        cout << ans << endl;
    }
    return 0;
}