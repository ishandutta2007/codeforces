#include<iostream>
#include<vector>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>c(n+1,0);
        for(int&t:v)
            cin>>t,c[t]++;
        priority_queue<int,vector<int>,greater<int> >pq;
        for(int i=0;i<=n;i++)
            if(c[i]==0)
                pq.ep(i);
        vector<int>ov;
        auto oper=[&](int x)
        {
            int nx=pq.top();
            pq.pop();
            c[v[x]]--;
            if(c[v[x]]==0)
                pq.ep(v[x]);
            v[x]=nx;
            c[nx]++;
            ov.eb(x);
            return;
        };
        while(pq.top()!=n)
            oper(pq.top());
        for(int i=0;i<n;i++)
        {
            if(v[i]==i)
                continue;
            if(pq.top()==i)
            {
                oper(i);
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(v[j]==i)
                {
                    oper(j),oper(i);
                    break;
                }
            }
        }
        cout<<ov.size()<<'\n';
        for(int&t:ov)
            cout<<t+1<<' ';
        cout<<'\n';
    }
    cout.flush();
    return 0;
}