#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c%3==0)
            cout<<a<<'\n';
        else if(c%3==1)
            cout<<b<<'\n';
        else
            cout<<(a^b)<<'\n';
    }
    cout<<endl;
    return 0;
}