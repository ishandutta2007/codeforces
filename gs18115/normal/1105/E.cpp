#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,bound;
bool adj[45][45];
LL memo[2345678];
LL bt1(LL lev,LL mask)
{
    if(memo[mask]>0||mask==0)
        return memo[mask];
    if(lev==N-bound)
        return memo[mask]=__builtin_popcount(mask);
    LL m0=mask;
    if(mask>>lev&1)
        for(LL i=bound+lev+1;i<N;i++)
            if(adj[bound+lev][i])
                mask&=~(1<<i-bound);
    return memo[m0]=max(bt1(lev+1,mask),bt1(lev+1,m0&~(1<<lev)));
}
LL bt2(LL lev,LL m1,LL m2)
{
    if(lev==bound)
        return __builtin_popcount(m1)+bt1(0,m2);
    LL m0=m1;
    LL m02=m2;
    if(m1>>lev&1)
    {
        for(LL i=lev+1;i<bound;i++)
            if(adj[lev][i])
                m1&=~(1<<i);
        for(LL i=bound;i<N;i++)
            if(adj[lev][i])
                m2&=~(1<<i-bound);
    }
    return max(bt2(lev+1,m1,m2),bt2(lev+1,m0&~(1<<lev),m02));
}
map<string,LL>M;
vector<LL>V;
LL Q,i,j,k;
LL type,t,P;
string S;
bool chk[45];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>Q>>N;
    for(i=0;i<Q;i++)
    {
        cin>>type;
        if(type==1)
        {
            for(j=0;j<V.size();j++)
                for(k=j+1;k<V.size();k++)
                    adj[V[j]][V[k]]=adj[V[k]][V[j]]=true;
            for(j=0;j<V.size();j++)
                chk[V[j]]=false;
            V.clear();
        }
        else
        {
            cin>>S;
            t=M[S];
            if(t==0)
                M[S]=t=++P;
            if(!chk[--t])
            {
                V.push_back(t);
                chk[t]=true;
            }
        }
    }
    for(j=0;j<V.size();j++)
        for(k=j+1;k<V.size();k++)
            adj[V[j]][V[k]]=adj[V[k]][V[j]]=true;
    for(j=0;j<V.size();j++)
        chk[V[j]]=false;
    V.clear();
    bound=N>>1;
    cout<<bt2(0,(1<<bound)-1,(1<<N-bound)-1)<<endl;
    return 0;
}