#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int n;
ll a[maxn];
ll calc(int x){
    ll res=0,last;
    last=0;
    for (int i=x-1;i>=1;i--){
        ll tmp=last/a[i]+1;
        res+=tmp; last=tmp*a[i];
    }
    last=0;
    for (int i=x+1;i<=n;i++){
        ll tmp=last/a[i]+1;
        res+=tmp; last=tmp*a[i];
    }
    return res;
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    ll ans=calc(1);
    for (int i=2;i<=n;i++) ans=min(ans,calc(i));
    cout << ans << endl;
}