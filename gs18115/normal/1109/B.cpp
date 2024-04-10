#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i,j,cnt;
char S[123456],S2[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    N=strlen(S);
    for(i=1;i<N>>1;i++)
        if(S[i]!=S[i-1])
            break;
    if(i>=N>>1)
        return cout<<"Impossible"<<endl,0;
    for(i=1;i<=N>>1;i++)
    {
        cnt=0;
        for(j=i;j<N;j++)
            S2[cnt++]=S[j];
        for(j=0;j<i;j++)
            S2[cnt++]=S[j];
        for(j=0;j<N;j++)
            if(S[j]!=S2[j])
                break;
        if(j>=N)
            continue;
        for(j=0;j<N>>1;j++)
            if(S2[j]!=S2[N-j-1])
                break;
        if(j>=N>>1)
            return cout<<1<<endl,0;
    }
    cout<<2<<endl;
    return 0;
}