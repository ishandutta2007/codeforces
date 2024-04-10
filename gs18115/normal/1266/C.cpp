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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c;
    cin>>r>>c;
    if(r==1&&c==1)
        return cout<<0<<endl,0;
    if(r==1)
    {
        for(int i=0;i<c;i++)
            cout<<i+2<<' ';
        cout<<endl;
        return 0;
    }
    if(c==1)
    {
        for(int i=0;i<r;i++)
            cout<<i+2<<'\n';
        cout<<endl;
        return 0;
    }
    for(int i=0;i++<r;)
    {
        for(int j=0;j++<c;)
        {
            cout<<j*(i+c)<<' ';
        }
        cout<<'\n';
    }
    cout<<endl;
    return 0;
}