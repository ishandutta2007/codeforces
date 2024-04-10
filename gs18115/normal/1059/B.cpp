#include<iostream>
using namespace std;
typedef long long LL;
const LL MAXN=1010;
char S[MAXN][MAXN];
const LL chkx[8]={1,1,1,0,0,-1,-1,-1};
const LL chky[8]={1,0,-1,1,-1,1,0,-1};
inline bool check(const LL&I,const LL&J)
{
    bool flag=false;
    for(LL i=0;i<8;i++)
    {
        bool flag2=true;
        for(LL j=0;j<8;j++)
        {
            if(S[I+chkx[j]-chkx[i]][J+chky[j]-chky[i]]==0)
            {
                flag2=false;
                break;
            }
        }
        if(flag2)
        {
            flag=true;
            break;
        }
    }
    return !flag;
}
LL N,M,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=2;i<N+2;i++)
    {
        cin>>S[i]+2;
        for(j=2;j<M+2;j++)
            S[i][j]=S[i][j]=='#'?1:0;
    }
    for(i=2;i<N+2;i++)
    {
        for(j=2;j<M+2;j++)
        {
            if(S[i][j]==1)
                if(check(i,j))
                    return cout<<"NO"<<endl,0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}