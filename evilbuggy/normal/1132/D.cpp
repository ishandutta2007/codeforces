#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[200005], b[200005], c[200005];

bool check(int n, ll p, int k){
    priority_queue<pair<ll, int> > pq;
    for(int i = 1; i <= n; i++){
        c[i] = a[i];
        pq.push({-(c[i]/b[i]), i});
    }
    for(int i = 1; i <= k; i++){
        pair<ll, int> y = pq.top();
        pq.pop();
        if(1-y.first < i)return false;
        c[y.second] += p;
        pq.push({-(c[y.second]/b[y.second]), y.second});
    }
    return true;
}

ll search(int n, int k){
    ll l = 0, r = 2e12;
    bool tmp = false;
    while(l < r){
        ll m = l + (r - l)/2;
        if(check(n, m, k)){
            r = m;
            tmp = true;
        }else{
            l = m + 1;
        }
    }
    if(tmp)return l;
    return -1;
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

    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
    }
    // cout<<check(n, 5, k)<<endl;
    cout<<search(n, k)<<endl;
}