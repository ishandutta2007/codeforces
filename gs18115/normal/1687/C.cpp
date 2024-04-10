#include<iostream>
#include<vector>
#include<set>
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
const ll INF=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(n);
        for(int&t:a)
            cin>>t;
        for(int&t:b)
            cin>>t;
        for(int i=0;i<n;i++)
            a[i]-=b[i];
        vector<ll>p(1,0);
        for(int&t:a)
            p.eb(p.back()+t);
        set<int>stt;
        for(int i=0;i++<n;)
            if(p[i]!=0)
                stt.ep(i);
        vector<pi>oq;
        vector<vector<int> >v(n+1);
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin>>l>>r;
            if(p[l-1]==0&&p[r]==0)
                oq.eb(l-1,r);
            else
                v[l-1].eb(r),v[r].eb(l-1);
        }
        while(!oq.empty())
        {
            int l=oq.back().fi,r=oq.back().se;
            oq.pop_back();
            if(l>r)
                swap(l,r);
            auto it=stt.lower_bound(l);
            while(it!=stt.end()&&*it<=r)
            {
                p[*it]=0;
                for(int t:v[*it])
                    if(p[t]==0)
                        oq.eb(t,*it);
                stt.erase(it);
                it=stt.lower_bound(l);
            }
        }
        if(stt.empty())
            cout<<"yes";
        else
            cout<<"no";
        cout<<'\n';
    }
    return 0;
}