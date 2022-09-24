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
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        ll k;
        cin>>n>>k;
        if(k!=0)
            k=k%2==1?1:2;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        for(int i=0;i<k;i++)
        {
            int mx=-2*inf;
            for(int&t:v)
                mx=max(mx,t);
            for(int&t:v)
                t=mx-t;
        }
        for(int&t:v)
            cout<<t<<' ';
        cout<<'\n';
    }
    cout.flush();
    return 0;
}