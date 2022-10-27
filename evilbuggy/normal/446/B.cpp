#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll a[1005][1005];
ll sumr[1000005], sumc[1000005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, p;
    cin>>n>>m>>k>>p;
    priority_queue<ll> rq, cq;
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            tmp += a[i][j];
        }
        rq.push(tmp);
    }
    for(int j = 1; j <= m; j++){
        int tmp = 0;
        for(int i = 1; i <= n; i++){
            tmp += a[i][j];
        }
        cq.push(tmp);
    }
    sumr[0] = 0;
    sumc[0] = 0;
    int l = 1;
    while(l <= k){
        ll x = rq.top();
        ll y = cq.top();
        rq.pop();
        cq.pop();
        sumr[l] = sumr[l-1] + x;
        sumc[l] = sumc[l-1] + y;
        rq.push(x - m*p);
        cq.push(y - n*p);
        l++;
    }
    ll ans = LLONG_MIN;
    for(int i = 0; i <= k; i++){
        ans = max(ans, sumr[i] + sumc[k-i] - 1LL*i*(k-i)*p);
    }
    cout<<ans<<endl;
}