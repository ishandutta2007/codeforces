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
const int mxn=1e5;
int cal[100010];
inline int mxover(vector<ll>v)
{
    ll prv=INF;
    sort(all(v));
    int cumc=0,mc=0;
    for(ll&t:v)
    {
        if(t==prv)
            mc=max(mc,++cumc);
        else
            prv=t,mc=max(mc,cumc=1);
    }
    return mc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    int sqn=320;
    int mx=1;
    for(int i=-sqn-1;i<=sqn+1;i++)
    {
        vector<ll>lst;
        for(int j=0;j<n;j++)
            lst.eb((ll)v[j]-(ll)i*j);
        mx=max(mx,mxover(lst));
    }
    for(int i=0;i<n;i++)
    {
        vector<ll>lst;
        for(int j=i+1;j<n&&j<=i+sqn;j++)
            if((v[j]-v[i])%(j-i)==0)
                lst.eb((v[j]-v[i])/(j-i));
        mx=max(mx,1+mxover(lst));
    }
    cout<<n-mx<<endl;
    return 0;
}