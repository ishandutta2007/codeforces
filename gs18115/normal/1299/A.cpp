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
int c[35];
ll d[35];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll>v(n);
    for(ll&t:v)
        cin>>t;
    for(ll&t:v)
    {
        for(int i=0;i<32;i++)
            if(t>>i&1)
                c[i]++,d[i]=t;
    }
    int i;
    for(i=32;i-->0;)
        if(c[i]==1)
            break;
    if(i<0)
    {
        for(ll&t:v)
            cout<<t<<' ';
        cout<<endl;
        return 0;
    }
    cout<<d[i]<<' ';
    ll x=d[i];
    for(ll&t:v)
        if(t!=x)
            cout<<t<<' ';
    return 0;
}