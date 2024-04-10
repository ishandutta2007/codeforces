#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

int n;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=3; i<=n;i++) {
        ans+=(long long)(i)*(i-1);
    }
    cout<<ans;
}