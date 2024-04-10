#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+10;
vector<int> a;
vector<pi> b[maxn];
int n,m;
ll ans;
ll solve(){
    sort(a.begin(),a.end());
    ll ret=0,sum=0;
    for (int i=0;i<a.size();i++){
        ret+=1ll*a[i]*i-sum;
        sum+=a[i];
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            int x; scanf("%d",&x);
            b[x].pb((pi){i,j});
        }
    for (int i=1;i<=100000;i++){
        a.clear();
        for (auto x:b[i]) a.pb(x.F);
        ans+=solve();
        a.clear();
        for (auto x:b[i]) a.pb(x.S);
        ans+=solve();
    }
    cout << ans << endl;
}