#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long ll;
string s;
int n,k1,k2,a[N],b[N],d[N];
ll ans;
priority_queue<int>pq;
static int myabs(int x)
{
    return x>=0?x:-x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k1>>k2;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        d[i]=myabs(a[i]-b[i]);
        ans+=(ll)d[i]*d[i];
        pq.push(d[i]);
    }
    for(int i=1;i<=k1+k2;i++){
        int tp=pq.top();
        pq.pop();
        ans-=(ll)tp*tp;
        int c=myabs(tp-1);
        ans+=(ll)c*c;
        pq.push(c);
    }
    cout<<ans;
    return 0;
}