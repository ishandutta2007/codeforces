#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int _,n,a[105],b[105],sum,best;
long long ans;
bitset<10005> f[105];
int main(){
    cin >> _;
    while (_--){
        cin >> n; ans=0; sum=0;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        for (int i=1;i<=n;i++){
            ans+=a[i]*a[i]+b[i]*b[i];
            sum+=a[i]+b[i];
            f[i].reset();
        }
        ans=ans*(n-2);
        f[0][0]=1;
        for (int i=1;i<=n;i++) f[i]=(f[i-1]<<a[i])|(f[i-1]<<b[i]);
        best=inf;
        for (int i=0;i<=10000;i++) 
            if (f[n][i]) best=min(best,i*i+(sum-i)*(sum-i));
        ans+=best;
        cout << ans << endl;
    }
}