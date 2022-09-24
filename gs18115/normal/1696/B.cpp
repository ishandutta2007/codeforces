#include<iostream>
#include<vector>
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
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        vector<int>p;
        for(int i=0;i<n;i++)
            if(v[i]!=0)
                p.eb(i);
        if(p.empty())
            cout<<0;
        else
        {
            int f=1;
            for(int i=1;i<(int)p.size();i++)
                if(p[i-1]+1!=p[i])
                    f=0;
            if(f==1)
                cout<<1;
            else
                cout<<2;
        }
        cout<<'\n';
    }
    return 0;
}