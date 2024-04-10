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
int query(string s)
{
    cout<<"? "<<s<<endl;
    int x;
    cin>>x;
    return x;
}
void answer(int x)
{
    cout<<"! "<<x<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>w(m);
    for(int i=0;i<m;i++)
    {
        string s;
        for(int j=0;j<m;j++)
            s.push_back(i==j?'1':'0');
        w[i]=query(s);
    }
    vector<int>id(m);
    for(int i=0;i<m;i++)
        id[i]=i;
    sort(all(id),[&](int x,int y){return w[x]<w[y];});
    string s;
    for(int i=0;i<m;i++)
        s.push_back('0');
    int pw=0;
    for(int i=0;i<m;i++)
    {
        s[id[i]]='1';
        int cw=query(s);
        if(cw!=pw+w[id[i]])
            s[id[i]]='0';
        else
            pw=cw;
    }
    cout<<"! "<<pw<<endl;
    return 0;
}