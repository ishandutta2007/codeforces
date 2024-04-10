#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
priority_queue<PL,vector<PL> >pq;
LL N,i,j;
LL A[1234567];
bool dp[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        pq.push({A[i],i});
    }
    pq.pop();
    while(!pq.empty())
    {
        i=pq.top().second;
        pq.pop();
        for(j=i;(j-=A[i])>=0;)
        {
            if(!dp[j]&&A[i]<A[j])
            {
                dp[i]=true;
                break;
            }
        }
        for(j=i;(j+=A[i])<N;)
        {
            if(!dp[j]&&A[i]<A[j])
            {
                dp[i]=true;
                break;
            }
        }
    }
    for(i=0;i<N;i++)
        cout<<(dp[i]?'A':'B');
    cout<<endl;
    return 0;
}