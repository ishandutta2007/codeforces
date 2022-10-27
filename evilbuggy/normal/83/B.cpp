#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll k, a[100005];

ll findSum(ll val){
    ll ret = 0;
    for(int i = 1; i <= n; i++){
        ret += min(val, a[i]);
    }
    return ret;
}

queue<int> search(ll l, ll r){
    while(l < r){
        ll m = l + (r - l + 1)/2;
        ll tmp = findSum(m);
        if(tmp >= k){
            r = m - 1;
        }else{
            l = m;
        }
    }
    ll req = k - findSum(l);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        a[i] = max(0LL, a[i] - l);
        if(a[i] > 0)q.push(i);
    }
    while(req--){
        int y = q.front();
        q.pop();
        a[y]--;
        if(a[y] > 0)q.push(y);
    }
    return q;
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

    cin>>n>>k;
    ll sum = 0, ind = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
        if(a[ind] <= a[i])ind = i;
    }
    if(sum < k)cout<<-1<<endl;
    else{
        queue<int> ans = search(0, a[ind]);
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }

}