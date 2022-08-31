#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+3;
typedef long long ll;
typedef pair<ll,ll> pi;
ll a[maxn],v[maxn],s[maxn];
int n,m;
pi b[maxn];
int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i].first >> b[i].second;
    sort(b,b+m);
    for (int i=0;i<m;i++) v[i]=b[i].first,s[i+1]=s[i]+b[i].second;
    v[m]=1e9+7;
    for (int i=0;i<n;i++) cout << s[lower_bound(v,v+m+1,a[i]+1)-v] << ' ';
    cout << endl;
}