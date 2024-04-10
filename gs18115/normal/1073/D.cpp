#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL nxt[1234567],prv[1234567];
LL A[1234567];
LL N,T,S,i,D,C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>T;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=1;i<N;i++)
        nxt[i-1]=i,prv[i]=i-1;
    nxt[N-1]=0;
    prv[0]=N-1;
    for(i=0;i<N;i++)
        S+=A[i];
    /*for(i=0;i<N;i++)
        pq.push(A[i]);*/
    D=0;
    C=N;
    i=0;
    while(C>0)
    {
        if(S==0)
            break;
        if(T>=S)
            D+=C*(T/S),T%=S;
        if(A[i]>T)
            nxt[prv[i]]=nxt[i],prv[nxt[i]]=prv[i],S-=A[i],C--;
        else
            T-=A[i],D++;
        i=nxt[i];
    }
    cout<<D<<endl;
    return 0;
}