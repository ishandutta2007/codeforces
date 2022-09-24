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
        cin>>n;
        vector<int>v(n);
        int s=0;
        for(int&t:v)
            cin>>t,s+=t;
        if(s<0)
        {
            cout<<"YES\n";
            sort(all(v));
            for(int&t:v)
                cout<<t<<' ';
            cout<<'\n';
        }
        else if(s>0)
        {
            cout<<"YES\n";
            sort(all(v),greater<int>());
            for(int&t:v)
                cout<<t<<' ';
            cout<<'\n';
        }
        else
            cout<<"NO\n";
    }
    return 0;
}