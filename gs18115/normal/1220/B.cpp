#include<iostream>
#include<vector>
#include<cmath>
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
int n,i,j;
int a[1010][1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    int g=0;
    for(i=1;i<n;i++)
        g=__gcd(g,a[0][i]);
    int t=a[0][1]/g;
    int t2=a[0][2]/g;
    int f=(int)(sqrt(a[1][2]/t/t2)+0.5);
    cout<<g/f;
    for(i=1;i<n;i++)
        cout<<' '<<a[0][i]/g*f;
    cout<<endl;
    return 0;
}