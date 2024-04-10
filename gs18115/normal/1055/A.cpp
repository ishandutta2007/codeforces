#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,S,i;
LL A[1234567];
LL B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        cin>>B[i];
    if(A[0]==0)
        return cout<<"NO"<<endl,0;
    if(A[S-1]==1)
        return cout<<"YES"<<endl,0;
    if(B[S-1]==0)
        return cout<<"NO"<<endl,0;
    for(i=N;i-->0;)
    {
        if(A[i]==1&&B[i]==1)
        {
            if(i>=S)
                return cout<<"YES"<<endl,0;
            else
                return cout<<"NO"<<endl,0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}