#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL C,i,N,maxi;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=1;i<=N;i++)
        cin>>A[i];
    A[0]=0;
    A[N+1]=1001;
    for(i=1;i<=N;i++)
    {
        if(A[i]==A[i-1]+1&&A[i]==A[i+1]-1)
            C++;
        else
            C=0;
        maxi=max(maxi,C);
    }
    cout<<maxi<<endl;
    return 0;
}