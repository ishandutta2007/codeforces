#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx,mn,n,k,p,q,a,b;

int main(){
    cin >> n >> k;
    cin >> a >> b;
    mx=mn=__gcd(n*k,abs(a-b));
    for (int i=0;i<n;i++){
        ll ret=__gcd(n*k,abs(k*i-a-b));
        //cout<<abs(k*i-a-b)<<endl;
        mx=max(mx,ret);
        mn=min(mn,ret);
    }
    for (int i=0;i<n;i++){
        ll ret=__gcd(n*k,abs(k*i-a+b));
        //cout<<abs(k*i-a+b)<<endl;
        mx=max(mx,ret);
        mn=min(mn,ret);
    }
    cout << n*k/mx << ' ' << n*k/mn << endl;
}