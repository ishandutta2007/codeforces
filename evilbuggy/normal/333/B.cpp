#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int r[1005], c[1005], pr[1005], pc[1005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y;
    cin>>n>>m;

    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));

    while(m--){
        cin>>x>>y;
        r[x] = 1;
        c[y] = 1;
    }
    int ans = 0;
    for(int i = 2; i < n; i++){
        ans += 2 - (r[i] + c[i]);
    }
    if(n%2 == 1 && !r[n/2 + 1] && !c[n/2 + 1])ans--;
    cout<<ans<<endl;
}