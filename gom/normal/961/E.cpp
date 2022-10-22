#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,a[N];ll ans;
int tree[N];
priority_queue<P,vector<P>,greater<P>> pq;
void add(int c,int x)
{
    while(c<=n+1){
        tree[c]+=x;
        c+=c&-c;
    }
}
int get(int x)
{
    int res=0;
    while(x){
        res+=tree[x];
        x-=x&-x;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=min(a[i],n);
        pq.push(P(a[i],i));
    }
    for(int i=1;i<=n;i++){
        add(1,1);
        add(a[i]+1,-1);
        while(pq.size()!=0&&pq.top().first==i){
            P tp=pq.top();
            pq.pop();
            //cout<<i<<" "<<tp.first<<" "<<tp.second<<" "<<get(tp.first)<<endl;
            ans+=get(tp.second);
            if(a[tp.second]>=tp.second)
                ans--;
        }
    }
    cout<<ans/2;
}