#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,u[1005],v[1005];
vector <int> ans;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> u[i] >> v[i];
    while (1){
        ans.clear();
        for (int i=1;i<=n;i++) if ((u[i]+v[i])&1) ans.pb(i);
        if (ans.size()==0){
            for (int i=1;i<=n;i++){
                int p=u[i]+v[i],q=u[i]-v[i];
                u[i]=p/2; v[i]=q/2;
            }
        } else if (ans.size()==n){
            for (int i=1;i<=n;i++){
                int p=u[i]+v[i]+1,q=u[i]-v[i]+1;
                u[i]=p/2; v[i]=q/2;
            }
        } else {
            break;
        }
    }
    cout << ans.size() << endl;
    for (auto x:ans) cout << x << ' '; cout << endl;
    return 0;
}