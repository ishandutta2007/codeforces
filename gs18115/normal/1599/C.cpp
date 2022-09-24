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
    int n;
    cin>>n;
    int p;
    {
        double dp;
        cin>>dp;
        p=(int)(dp*10000+0.5);
    }
    int s=0,e=n;
    while(s<e)
    {
        int m=s+(e-s)/2;
        bool f;
        {
            ll m1=m,m2=n-m;
            ll n0=m1*(m1-1)*(m1-2)/6;
            ll n1=m1*(m1-1)*m2/2;
            ll n2=m1*m2*(m2-1)/2;
            ll n3=m2*(m2-1)*(m2-2)/6;
            ll all=n0+n1+n2+n3;
            f=(n0*2+n1*2+n2)*10000>=(all*2)*p;
        }
        if(f)
            e=m;
        else
            s=m+1;
    }
    cout<<s<<endl;
    return 0;
}