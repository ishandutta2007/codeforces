#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    long long int n,m,k;
    while(q--){
        cin>>n>>m>>k;
        if(max(n,m) > k){
            cout<<-1<<endl;
        }else{
            long long int ans = min(m, n), y = abs(m-n);
            k -= min(m,n);
            if(y%2 == 0 && k%2 == 0){
                ans += k;
            }else if(y%2 == 0 && k%2 == 1){
                ans += k - 2;
            }else{
                ans += k-1;
            }
            cout<<ans<<endl;
        }
    }
}