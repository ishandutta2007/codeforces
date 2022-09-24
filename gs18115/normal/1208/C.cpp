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
int n,i,j,k,l;
int a[2010][2010];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            for(k=0;k<n/4;k++)
                for(l=0;l<n/4;l++)
                    a[4*k+i][4*l+j]=k*n*4+16*l+i*4+j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    cout<<endl;
    return 0;
}