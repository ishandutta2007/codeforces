#include<iostream>
using namespace std;
typedef long long LL;
const LL MAXN=2e5+10;
LL N,H;
LL A[MAXN],B[MAXN];
LL sume,sumg,maxi;
LL i,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>H;
    cin>>A[0]>>B[0];
    sume=0;
    sumg=B[0]-A[0];
    maxi=sumg+H;
    for(i=1;i<N;i++)
    {
        cin>>A[i]>>B[i];
        sume+=A[i]-B[i-1];
        sumg+=B[i]-A[i];
        while(sume>=H)
        {
            sume-=A[t+1]-B[t];
            sumg-=B[t]-A[t];
            t++;
        }
        maxi=max(maxi,sumg+H);
    }
    cout<<maxi<<endl;
    return 0;
}