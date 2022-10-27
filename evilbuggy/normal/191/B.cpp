#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll b;
pair<ll, int> a[100005];

bool cmp(pair<ll, int> &a, pair<ll, int> &b){
    return a.first > b.first;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n>>k>>b;
    for(int i = 1; i <= n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n, cmp);
    ll sum = 0;
    int ans = n;
    for(int i = 1; i <= k; i++){
        sum += a[i].first;
        ans = min(ans, a[i].second);
    }
    if(sum <= b){
        cout<<n<<endl;
        return 0;
    }
    for(int i = k + 1; i < n; i++){
        if(sum - a[k].first + a[i].first > b)ans = min(ans, a[i].second);
    }
    cout<<ans<<endl;
}