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
    int n,m;
    cin>>n>>m;
    int s=0;
    for(int i=0;i<n;i++)
        s+=i/2;
    if(m>s)
        return cout<<-1<<endl,0;
    s=0;
    bool f=0;
    int in=1e9-5-n;
    for(int i=0;i<n;i++)
    {
        if(f)
        {
            cout<<in+i<<' ';
            continue;
        }
        if(s+i/2>m)
        {
            int c=m-s;
            cout<<(i+(i-c*2)+1)*(n+1)<<' ';
            f=1;
            continue;
        }
        s+=i/2;
        cout<<(i+1)*(n+1)<<' ';
    }
    cout<<endl;
    return 0;
}