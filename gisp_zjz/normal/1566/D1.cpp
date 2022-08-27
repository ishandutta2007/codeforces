#include<bits/stdc++.h>
using namespace std;
int _,n,k,a[305];
int main(){
    cin >> _;
    while (_--){
        cin >> k >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                ans+=a[i]<a[j];
        cout << ans << endl;
    }
}