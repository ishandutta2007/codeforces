#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,n,ans;
int main(){
    cin >> a >> b >> n; ans=0;
    for (int i=0;i<=n;i++) if (i<=a&&n-i<=b) ans++;
    cout << ans << endl;
}