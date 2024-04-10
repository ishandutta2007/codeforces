#include <bits/stdc++.h>

using namespace std;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n,k;
    cin>>n>>k;
    long long int r = 2*n;
    long long int g = 5*n;
    long long int b = 8*n;
    long long int ans = (r/k) + (g/k) + (b/k);
    if(r%k != 0)ans++;
    if(g%k != 0)ans++;
    if(b%k != 0)ans++;
    cout<<ans<<endl;

}