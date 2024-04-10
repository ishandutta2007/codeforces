#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,m,M,i,c;
LL A[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        m=max(m,A[i]);
    }
    for(i=0;i<N;i++)
    {
        if(m==A[i])
            c++;
        else
            c=0;
        M=max(M,c);
    }
    cout<<M<<endl;
    return 0;
}