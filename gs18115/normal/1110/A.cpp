#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL B,N,i,ans;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>B>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    if(B&1)
    {
        for(i=0;i<N;i++)
            ans+=A[i];
    }
    else
        ans=A[N-1];
    if(ans&1)
        cout<<"odd";
    else
        cout<<"even";
    cout<<endl;
    return 0;
}