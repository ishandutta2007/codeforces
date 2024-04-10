#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,i,S,ans,T,D;
LL A[1234567],C[1234567];
priority_queue<PL,vector<PL>,greater<PL> >pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
    {
        cin>>C[i];
        pq.emplace(C[i],i);
        S+=A[i];
    }
    for(i=0;i<M;i++)
    {
        cin>>T>>D;
        ans=0;
        if(S<D)
            S=0;
        else
        {
            S-=D;
            if(A[--T]<D)
            {
                ans=A[T]*C[T];
                D-=A[T];
                A[T]=0;
                while(!pq.empty())
                {
                    PL t=pq.top();
                    if(A[t.second]>D)
                    {
                        ans+=C[t.second]*D;
                        A[t.second]-=D;
                        break;
                    }
                    else
                    {
                        ans+=A[t.second]*C[t.second];
                        D-=A[t.second];
                        A[t.second]=0;
                        pq.pop();
                    }
                }
            }
            else
            {
                A[T]-=D;
                ans=C[T]*D;
            }
        }
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}