#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n, k;
    cin>>n>>k;
    long long int ans = k/n;
    if(k%n != 0){
        ans++;
    }
    cout<<ans<<endl;
}