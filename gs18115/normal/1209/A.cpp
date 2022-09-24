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
int n,i,j,C;
int a[100010];
bool c[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(!c[a[i]])
        {
            C++;
            for(j=a[i];j<=100;j+=a[i])
                c[j]=true;
        }
    }
    cout<<C<<endl;
    return 0;
}