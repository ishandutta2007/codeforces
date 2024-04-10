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
inline int qry(int x)
{
    cout<<"? "<<x<<endl;
    cin>>x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>ok(n+1,0);
        vector<int>p(n+1,0);
        for(int i=0;i++<n;)
        {
            if(ok[i]==1)
                continue;
            vector<int>cyc;
            int z=qry(i);
            int fz=z;
            cyc.eb(z);
            z=qry(i);
            while(z!=fz)
            {
                cyc.eb(z);
                z=qry(i);
            }
            int s=cyc.size();
            for(int i=0;i<s;i++)
                p[cyc[i]]=cyc[(i+1)%s],ok[cyc[i]]=1;
        }
        p.erase(p.begin());
        cout<<"!";
        for(int&t:p)
            cout<<' '<<t;
        cout<<endl;
    }
    return 0;
}