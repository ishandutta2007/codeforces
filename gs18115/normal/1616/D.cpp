#include<iostream>
#include<vector>
#include<set>
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
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int x;
        cin>>x;
        vector<int>f1(n),f2(n);
        for(int i=0;i<n-1;i++)
            if(v[i]+v[i+1]<2*x)
                f1[i]=1;
        for(int i=0;i<n-2;i++)
            if(v[i]+v[i+1]+v[i+2]<3*x)
                f2[i]=1;
        vector<int>d1(n+1),d2(n+1),d3(n+1),d4(n+1);
        d1[0]=1;
        d2[0]=-inf,d3[0]=-inf;
        d4[0]=1;
        int m=1;
        for(int i=1;i<n;i++)
        {
            d1[i]=i==1?1:1+d4[i-2];
            d2[i]=f1[i-1]==1?-inf:1+d1[i-1];
            d3[i]=i==1?-inf:(f1[i-1]==1||f2[i-2]==1?-inf:max({d2[i-1],d3[i-1]})+1);
            m=max(m,d4[i]=max({d1[i],d2[i],d3[i],d4[i-1]}));
        }
        cout<<m<<'\n';
    }
    return 0;
}