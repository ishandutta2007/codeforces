#include <bits/stdc++.h>
#define N 1005
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m,a[N];
int ans1,ans2;
priority_queue<int,vector<int>,greater<int>>pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pq.push(a[i]);
    for(int i=1;i<=m;i++){
        int tp=pq.top();
        pq.pop();
        pq.push(tp+1);
    }
    while(pq.size()){
        ans1=max(ans1,pq.top());
        pq.pop();
    }
    cout<<ans1<<" "<<a[n]+m;
    return 0;
}