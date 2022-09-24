#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18+7;
int dis[10010][1010];
int pa[10010][1010];
bitset<1010>inq[10010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>v(m);
    for(int&t:v)
        cin>>t;
    sort(all(v));
    int g,r;
    cin>>g>>r;
    queue<pi>q;
    for(int i=0;i<m;i++)
        fill(dis[i],dis[i]+g+1,inf);
    dis[0][0]=0;
    q.ep(0,0);
    while(!q.empty())
    {
        int i=q.front().fi,j=q.front().se;
        q.pop();
        if(i==m-1)
            continue;
        inq[i][j]=0;
        if(j==g)
        {
            if(dis[i][0]>dis[i][j]+1)
            {
                dis[i][0]=dis[i][j]+1;
                if(!inq[i][0])
                {
                    q.ep(i,0);
                    inq[i][0]=1;
                }
            }
            continue;
        }
        if(i!=0)
        {
            int tm=j+v[i]-v[i-1];
            if(tm<=g)
            {
                if(dis[i-1][tm]>dis[i][j])
                {
                    dis[i-1][tm]=dis[i][j];
                    if(!inq[i-1][tm])
                    {
                        q.ep(i-1,tm);
                        inq[i-1][tm]=1;
                    }
                }
            }
        }
        int tm=j+v[i+1]-v[i];
        if(tm>g)
            continue;
        if(dis[i+1][tm]>dis[i][j])
        {
            dis[i+1][tm]=dis[i][j];
            if(!inq[i+1][tm])
            {
                q.ep(i+1,tm);
                inq[i+1][tm]=1;
            }
        }
    }
    ll mn=INF;
    for(int i=0;i<=g;i++)
        mn=min(mn,(ll)dis[m-1][i]*(g+r)+i);
    if(mn>=(ll)inf*(g+r))
        mn=-1;
    cout<<mn<<endl;
    return 0;
}