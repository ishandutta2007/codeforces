#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,ans;
int main(){
    cin >> n >> b >> a; a*=5;
    ans=n;
    for (int i=0;i*a<=n;i++) ans=min(ans,(n-i*a)%b);
    cout << ans << endl;
    return 0;
}