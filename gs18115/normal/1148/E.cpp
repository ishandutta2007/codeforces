#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef pair<PL,LL>PLL;
const LL INF=1e18;
struct eve
{
    LL x,y,z;
    eve(LL x,LL y,LL z):x(x),y(y),z(z){}
};
vector<eve>V;
vector<PL>V2;
priority_queue<PLL,vector<PLL>,greater<PLL> >pq1,pq2;
LL N,i;
LL A[300010],B[300010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i++<N;)
        cin>>A[i];
    LL S=0;
    for(i=0;i++<N;)
    {
        cin>>B[i];
        S+=B[i]-A[i];
        V2.eb(A[i],i);
    }
    if(S!=0)
        return cout<<"NO"<<endl,0;
    sort(B+1,B+N+1);
    sort(V2.begin(),V2.end());
    for(i=0;i<N;i++)
    {
        if(B[i+1]>V2[i].fi)
            pq1.emplace(V2[i],i+1);
        else if(B[i+1]<V2[i].fi)
            pq2.emplace(V2[i],i+1);
    }
    while(!pq1.empty())
    {
        PLL tt1=pq1.top();
        pq1.pop();
        PLL tt2=pq2.top();
        pq2.pop();
        PL t1=tt1.fi;
        PL t2=tt2.fi;
        if(B[tt1.se]>B[tt2.se]||A[t1.se]>B[tt1.se]||A[t2.se]<B[tt2.se])
            return cout<<"NO"<<endl,0;
        LL mov=min(B[tt1.se]-A[t1.se],A[t2.se]-B[tt2.se]);
        A[t1.se]+=mov;
        A[t2.se]-=mov;
        V.eb(t1.se,t2.se,mov);
        if(A[t1.se]!=B[tt1.se])
            pq1.emplace(PL(A[t1.se],t1.se),tt1.se);
        if(A[t2.se]!=B[tt2.se])
            pq2.emplace(PL(A[t2.se],t2.se),tt2.se);
    }
    cout<<"YES\n"<<V.size();
    for(i=0;i<V.size();i++)
        cout<<'\n'<<V[i].x<<' '<<V[i].y<<' '<<V[i].z;
    cout<<endl;
    return 0;
}