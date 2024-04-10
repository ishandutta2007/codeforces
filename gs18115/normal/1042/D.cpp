#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL n=262144;
LL FT[267890];
inline void FI(LL I,LL diff)
{
    for(;I<=n;I+=I&-I)
        FT[I]+=diff;
    return;
}
inline LL FS(LL I)
{
    LL sum=0;
    for(;I>0;I=I&I-1)
        sum+=FT[I];
    return sum;
}
vector<LL>V;
LL N,T,A,i;
LL S[267890];
LL sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>T;
    T--;
    for(i=1;i<=N;i++)
    {
        cin>>A;
        S[i]=S[i-1]+A;
        V.push_back(S[i]);
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(i=1;i<=N;i++)
        FI(upper_bound(V.begin(),V.end(),S[i])-V.begin(),1);
    for(i=0;i<N;i++)
    {
        sum+=FS(upper_bound(V.begin(),V.end(),S[i]+T)-V.begin());
        FI(upper_bound(V.begin(),V.end(),S[i+1])-V.begin(),-1);
    }
    cout<<sum<<endl;
    return 0;
}