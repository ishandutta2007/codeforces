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
ll n,i;
ll a[200010];
ll S,cm,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<=inf;i*=2)
    {
        S=0;
        for(int j=0;j<n;j++)
            if(a[j]%(2*i)==i)
                S++;
        if(S>cm)
            cm=S,m=i;
    }
    cout<<n-cm;
    for(i=0;i<n;i++)
        if(a[i]%(2*m)!=m)
            cout<<'\n'<<a[i];
    cout<<endl;
    return 0;
}