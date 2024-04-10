#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef vector<LL>VL;
LL N,K,i,j,s;
LL C[234567];
pair<PL,LL>P[234567];
priority_queue<LL,vector<LL>,less<LL> >PQ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    for(i=0;i<N;i++)
        cin>>P[i].FI.FI;
    for(i=0;i<N;i++)
        cin>>P[i].FI.SE;
    for(i=0;i<N;i++)
        P[i].SE=i;
    sort(P,P+N);
    for(i=0;i<N;i++)
    {
        s=j=0;
        VL V;
        while(!PQ.empty()&&j<K)
        {
            j++;
            LL T=PQ.top();
            PQ.pop();
            V.PB(T);
            s+=T;
        }
        for(j=0;j<V.size();j++)
            PQ.push(V[j]);
        C[P[i].SE]=s+P[i].FI.SE;
        PQ.push(P[i].FI.SE);
    }
    for(i=0;i<N;i++)
        cout<<C[i]<<' ';
    return 0;
}