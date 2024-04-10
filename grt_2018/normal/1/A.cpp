#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a;
    long long ans=0;
    cin>>n>>m>>a;
    ans = (n-1)/a+1;
    ans*=(m-1)/a+1;
    cout<<ans;
}