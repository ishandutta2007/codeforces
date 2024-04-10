#include <bits/stdc++.h>

using namespace std;

long long int sum(long long int n){
    if(n == 0)return 0;
    if(n%2 == 0)return n/2;
    return -(n+1)/2;
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int l, r;
    int q;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<sum(r) - sum(l-1)<<endl;
    }


}