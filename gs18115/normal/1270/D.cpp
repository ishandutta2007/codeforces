#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
pi qu(vector<int>v)
{
    cout<<'?';
    for(int&t:v)
        cout<<' '<<t;
    cout<<endl;
    int x,y;
    cin>>x>>y;
    return pi(x,y);
}
int pa[100010],ver[100010];
int par(int x)
{
    if(pa[x]==0)
        return x;
    return pa[x]=par(pa[x]);
}
void uni(int x,int y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    if(ver[x]!=0)
        pa[y]=x;
    else
        pa[x]=y;
    return;
}
void chk(int x,int y)
{
    ver[par(x)]=1;
    ver[par(y)]=2;
    return;
}
priority_queue<pi,vector<pi>,greater<pi> >pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>v(n+1,-1),q;
    for(int i=1;i<=n;i++)
        pq.ep(v[i],i);
    for(int i=0;i<k-1;i++)
        q.eb(i+1);
    for(int i=k-1;i<n;i++)
    {
        q.eb(i+1);
        pi qq=qu(q);
        q.erase(find(all(q),qq.fi));
        v[qq.fi]=qq.se;
    }
    vector<int>x,y;
    for(int i=0;i++<n;)
    {
        if(v[i]!=-1)
            x.eb(i);
        else
            y.eb(i);
    }
    int ans;
    if(k==1)
        ans=1;
    else
    {
        q.clear();
        sort(all(x),[=](int p,int q){return v[p]<v[q];});
        int c=0;
        for(int i=0;i<y.size();i++)
        {
            q.clear();
            q.eb(x[0]);
            q.eb(x[1]);
            for(int j=0;j<y.size();j++)
                if(j!=i)
                    q.eb(y[j]);
            pi t=qu(q);
            if(t.fi==x[1])
                c++;
        }
        ans=c+1;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}