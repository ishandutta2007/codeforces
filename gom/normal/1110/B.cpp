#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,a[N],res;
priority_queue<int,vector<int>,greater<int>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    res=n;
    for(int i=1;i<=n-1;i++){
        pq.push(a[i+1]-a[i]-1);
    }
    for(int i=1;i<=n-k;i++){
        res+=pq.top(); pq.pop();
    }
    cout<<res;
    return 0;
}