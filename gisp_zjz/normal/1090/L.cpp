#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,a,b,k,ans,p,q;

int main(){
    cin >> t >> n >> a >> b >> k; ans=t;
    p=(n+1)/2; q=n/2;
    ans=min(ans,(p*a+q*b)/k);
    if (k>n) ans=0;
    if (k>p) ans=min(ans,q*b/(k-p));
    if (k>q) ans=min(ans,p*a/(k-q));
    cout << ans << endl;
}