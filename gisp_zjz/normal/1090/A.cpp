#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],mx,n,m,k,r,ans;

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        for (int j=0;j<a[i];j++){
            cin >> k;
            mx=max(mx,k);
            b[i]=max(b[i],k);
        }
    }
    for (int i=0;i<n;i++) ans+=(mx-b[i])*a[i];
    cout << ans << endl;
}