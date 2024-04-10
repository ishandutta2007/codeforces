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
const ll INF=1e18+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n=s.size();
    vector<int>v,v1,v2;
    for(int i=0;i<n;i++)
        if(s[i]=='(')
            v1.eb(i);
    for(int i=n;i-->0;)
        if(s[i]==')')
            v2.eb(i);
    for(int i=0;i<v1.size()&&i<v2.size();i++)
        if(v1[i]<v2[i])
            v.eb(v1[i]),v.eb(v2[i]);
    sort(all(v));
    if(v.empty())
        return cout<<0<<endl,0;
    cout<<1<<endl<<v.size()<<endl;
    for(auto&t:v)
        cout<<t+1<<' ';
    cout<<endl;
    return 0;
}