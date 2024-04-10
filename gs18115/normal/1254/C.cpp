#include<iostream>
#include<vector>
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
int n,i;
ll q(int i,int j,int k,int x)
{
    cout<<i<<' '<<j<<' '<<k<<' '<<x<<endl;
    ll p;
    cin>>p;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int N=1;
    int M=2;
    for(i=3;i<=n;i++)
        if(q(2,N,M,i)==-1)
            M=i;
    vector<pl>v;
    for(i=2;i<=n;i++)
    {
        if(i==M)
            continue;
        v.eb(q(1,N,M,i),i);
    }
    sort(all(v));
    vector<int>ans;
    ans.eb(N);
    ans.eb(M);
    if(v.size()==1)
        return cout<<0<<' '<<N<<' '<<M<<' '<<v[0].se<<endl,0;
    int fi=v[0].se;
    int se=v[1].se;
    vector<int>a2;
    for(i=1;i<v.size();i++)
    {
        se=v[i].se;
        if(q(2,N,fi,se)==1)
            ans.eb(fi),fi=se;
        else
            a2.eb(fi),fi=se;
    }
    ans.eb(fi);
    reverse(all(a2));
    for(int&t:a2)
        ans.eb(t);
    cout<<0;
    for(int&t:ans)
        cout<<' '<<t;
    cout<<endl;
    return 0;
}