#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll c[100005];
ll t[100005];

vector<ll> carr, tarr;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>t[i];
    }
    for(int i = 1; i < n; i++){
        carr.push_back(c[i+1] - c[i]);
        tarr.push_back(t[i+1] - t[i]);
    }
    sort(carr.begin(), carr.end());
    sort(tarr.begin(), tarr.end());
    if(c[1] == t[1] && c[n] == t[n] && tarr == carr)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}