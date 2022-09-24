#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
map<LL,LL>M;
vector<LL>V;
LL N,i;
LL S,S2,G;
LL A[505];
LL s,e,mid;
LL sz;
vector<LL>P;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        s=2;
        e=40000;
        while(s<e)
        {
            mid=s+e>>1;
            if(mid*mid*mid*mid<A[i])
                s=mid+1;
            else
                e=mid;
        }
        if(s*s*s*s==A[i])
        {
            M[s]+=4;
            P.push_back(s);
            continue;
        }
        s=2;
        e=1300000;
        while(s<e)
        {
            mid=s+e>>1;
            if(mid*mid*mid<A[i])
                s=mid+1;
            else
                e=mid;
        }
        if(s*s*s==A[i])
        {
            M[s]+=3;
            P.push_back(s);
            continue;
        }
        s=2;
        e=1500000000;
        while(s<e)
        {
            mid=s+e>>1;
            if(mid*mid<A[i])
                s=mid+1;
            else
                e=mid;
        }
        if(s*s==A[i])
        {
            M[s]+=2;
            P.push_back(s);
        }
        else
            V.push_back(A[i]);
    }
    N=V.size();
    for(i=0;i<N;i++)
    {
        for(LL j=i+1;j<N;j++)
        {
            G=gcd(V[i],V[j]);
            if(G>1&&G<V[i])
                P.push_back(G);
        }
    }
    sort(P.begin(),P.end());
    P.erase(unique(P.begin(),P.end()),P.end());
    for(i=0;i<N;i++)
    {
        for(LL j:P)
        {
            if(V[i]%j==0)
            {
                M[j]++;
                M[V[i]/j]++;
                V[i]=1;
                break;
            }
        }
    }
    sort(V.begin(),V.end());
    for(i=0;i<N&&V[i]==1;i++);
    S2=1;
    if(i<N)
    {
        sz=1;
        while(++i<N)
        {
            if(V[i]!=V[i-1])
            {
                S2=S2*(sz+1)*(sz+1)%MOD;
                sz=1;
            }
            else
                sz++;
        }
        S2=S2*(sz+1)*(sz+1)%MOD;
    }
    S=1;
    for(auto j:M)
        S=S*(j.second+1)%MOD;
    cout<<S*S2%MOD<<endl;
    return 0;
}