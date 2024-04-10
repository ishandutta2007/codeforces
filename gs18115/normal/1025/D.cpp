#include<iostream>
using namespace std;
typedef long long LL;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
bool pos[705][705],rt1[705][705],rt2[705][705],adj[705][705];
LL sz,i,j,N;
LL A[705];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            adj[i][j]=gcd(A[i],A[j])>1LL;
    rt1[0][0]=false;
    rt2[0][0]=adj[0][1];
    pos[0][0]=true;
    for(i=1;i<N;i++)
    {
        rt1[i][i]=adj[i][i-1];
        rt2[i][i]=adj[i][i+1];
        pos[i][i]=true;
    }
    for(sz=1;sz<N;sz++)
    {
        rt1[0][sz]=false;
        if(rt1[1][sz])
        {
            pos[0][sz]=true;
            if(adj[0][sz+1])
                rt2[0][sz]=true;
        }
        for(j=1;j<sz;j++)
        {
            if(rt2[0][j-1]&&rt1[j+1][sz])
            {
                pos[0][sz]=true;
                if(adj[j][sz+1])
                    rt2[0][sz]=true;
            }
        }
        if(rt2[0][sz-1])
        {
            pos[0][sz]=true;
            if(adj[sz][sz+1])
                rt2[0][sz]=true;
        }
        for(i=1;i<N-sz;i++)
        {
            if(rt1[i+1][i+sz])
            {
                pos[i][i+sz]=true;
                if(adj[i][i-1])
                    rt1[i][i+sz]=true;
                if(adj[i][i+sz+1])
                    rt2[i][i+sz]=true;
            }
            for(j=1;j<sz;j++)
            {
                if(rt2[i][i+j-1]&&rt1[i+j+1][i+sz])
                {
                    pos[i][i+sz]=true;
                    if(adj[i+j][i-1])
                        rt1[i][i+sz]=true;
                    if(adj[i+j][i+sz+1])
                        rt2[i][i+sz]=true;
                }
            }
            if(rt2[i][i+sz-1])
            {
                pos[i][i+sz]=true;
                if(adj[i+sz][i-1])
                    rt1[i][i+sz]=true;
                if(adj[i+sz][i+sz+1])
                    rt2[i][i+sz]=true;
            }
        }
    }
    cout<<(pos[0][N-1]?"Yes":"No")<<endl;
    return 0;
}