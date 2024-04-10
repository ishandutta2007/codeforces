#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL pa[234567];
LL par(LL I)
{
    if(pa[I]==-1)
        return I;
    return pa[I]=par(pa[I]);
}
void uni(LL X,LL Y)
{
    if(par(X)==par(Y))
        return;
    pa[par(X)]=par(Y);
    return;
}
vector<LL>V;
LL i,N,s;
LL C[234567],P[234567];
bool chk[234567],chk2[234567];
LL dfs(LL I,LL ans)
{
    if(chk2[I])
        return ans;
    chk2[I]=true;
    return dfs(P[I],min(C[I],ans));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    fill(pa,pa+N+2,-1);
    for(i=0;i<N;i++)
        cin>>C[i];
    for(i=0;i<N;i++)
    {
        cin>>P[i];
        uni(i,--P[i]);
    }
    for(i=0;i<N;i++)
    {
        if(!chk[par(i)])
        {
            V.push_back(par(i));
            chk[par(i)]=true;
        }
    }
    for(i=0;i<V.size();i++)
        s+=dfs(V[i],999999999999LL);
    cout<<s<<endl;
    return 0;
}