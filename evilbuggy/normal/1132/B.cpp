#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[300005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    int m, x;
    cin>>m;
    for(int i = 1; i <= m; i++){
        cin>>x;
        cout<<sum-a[x]<<endl;
    }
}