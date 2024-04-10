#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=2e18;
const LL inf=1e9+100;
LL SQRT(const LL&X)
{
    LL s,e,mid;
    s=1;
    e=min(X,inf);
    while(s<e)
    {
        mid=s+e>>1;
        if(mid*mid<X)
            s=mid+1;
        else
            e=mid;
    }
    if(s*s>X)
        s--;
    return s;
}
LL N,T,i,j;
vector<LL>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=2;i*i*i<INF;i++)
    {
        T=SQRT(i);
        if(T*T==i)
            continue;
        for(j=i*i*i;j<INF/i/i;j*=i*i)
            V.push_back(j);
        V.push_back(j);
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()));
    cin>>T;
    while(T--)
    {
        cin>>N;
        cout<<N-SQRT(N)-(upper_bound(V.begin(),V.end(),N)-V.begin())<<'\n';
    }
    cout<<endl;
    return 0;
}