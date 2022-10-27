#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin>>x;
        ans = max(ans, min(x-1, 1000000-x));
    }
    cout<<ans<<endl;
}