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
int n,i;
int A[2000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    if(n&1)
    {
        cout<<"YES"<<endl;
        for(i=0;i<n;i++)
        {
            A[i]=i*2+1;
            A[i+n]=i*2+2;
            if(i&1)
                swap(A[i],A[i+n]);
        }
        for(i=0;i<n*2;i++)
            cout<<A[i]<<' ';
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}