#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
const int maxn=1e5+10;
int _,n,t,ans;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> t; ans=1e9+3;
        for (int i=0;i<n;i++){
            int x; cin >> x;
            if (x==t) ans=min(ans,1);
            else if (x>t) ans=min(ans,2);
            else ans=min(ans,(t+x-1)/x);
        }
        cout << ans << endl;
    }
    return 0;
}