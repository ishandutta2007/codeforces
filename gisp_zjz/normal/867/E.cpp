#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,ans,k;

int main()
{
    ans=0;scanf("%d",&n);
    priority_queue<ll, vector<ll>, greater<ll> > q,a,b;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k);
        if (!q.empty()&&q.top()<k){
            ans+=k-q.top();
            q.pop();q.push(k);
        }
        q.push(k);
    }
    printf("%I64d\n",ans);
    return 0;
}