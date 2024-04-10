#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,p,K,i;
LL A[300010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>p>>K;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        LL c=A[i]*A[i]%p;
        c=c*c%p;
        c=(c+K*p-K*A[i])%p;
        A[i]=c;
    }
    sort(A,A+N);
    LL s=0,e=0;
    LL ans=0;
    while(s<N)
    {
        while(e<N&&A[e]==A[s])
            e++;
        ans+=(e-s)*(e-s-1)>>1;
        s=e;
    }
    cout<<ans<<endl;
    return 0;
}