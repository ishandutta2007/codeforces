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
int n,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<(i+j&1?'W':'B');
        cout<<endl;
    }
    return 0;
}