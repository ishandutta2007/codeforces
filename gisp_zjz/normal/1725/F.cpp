#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],l[MAXN],r[MAXN];
int ans[31];
int sum[1100005];
int solve_small(int range)
{
    int all=0;
    for(int i=0;i<=range+1;i++) sum[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]-l[i]+1>=range) all++;
        else
        {
            int lb=l[i]%range,rb=r[i]%range;
            if(lb>rb) all++;
            sum[lb]++; sum[rb+1]--;
        }
    }
    int res=all,s=0;
    for(int i=0;i<range;i++)
    {
        s+=sum[i];
        res=max(res,s+all);
    }
    return res;
}
int solve_large(int range)
{
    vector<P> v;
    int all=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]-l[i]+1>=range) all++;
        else
        {
            int lb=l[i]%range,rb=r[i]%range;
            if(lb>rb) all++;
            v.push_back(P(lb,1)); 
            v.push_back(P(rb+1,-1));
        }
    }
    sort(v.begin(),v.end());
    int res=all,s=0;
    for(auto p:v) s+=p.S,res=max(res,s+all);
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    scanf("%d",&q);
    for(int i=0;i<=20;i++) ans[i]=solve_small(1<<i);
    for(int i=21;i<30;i++) ans[i]=solve_large(1<<i);
    for(int i=0;i<q;i++)
    {
        int x,cnt; cnt=0;
        scanf("%d",&x);
        while(x%2==0) cnt++,x/=2;
        printf("%d\n",ans[cnt]);
    }
    return 0;
}