#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=998244353;
char S[1234567];
LL i,p,q,N,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cin>>S;
    for(i=1;i<N;i++)
        if(S[i]!=S[i-1])
            break;
    if(i>=N)
        return cout<<N*(N+1)/2%MOD<<endl,0;
    p=i;
    for(i=N;i-->0;)
        if(S[i]!=S[i-1])
            break;
    q=N-i;
    if(S[0]==S[N-1])
        cnt=(p+1)*(q+1);
    else
        cnt=p+q+1;
    cout<<cnt%MOD<<endl;
    return 0;
}