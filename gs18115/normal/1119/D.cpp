#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
priority_queue<PL,vector<PL>,greater<PL> >pq;
LL T,i,N;
PL Q[1234567];
LL S[1234567];
LL ss;
LL ans[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>S[i];
    sort(S,S+N);
    cin>>T;
    for(i=0;i<T;i++)
    {
        LL s,e;
        cin>>s>>e;
        Q[i].first=e-s+1;
        Q[i].second=i;
    }
    sort(Q,Q+T);
    for(i=1;i<N;i++)
        pq.emplace(S[i]-S[i-1],i);
    for(i=0;i<T;i++)
    {
        while(!pq.empty())
        {
            PL t=pq.top();
            if(t.first>Q[i].first)
                break;
            else
            {
                pq.pop();
                ss+=t.first;
                N--;
            }
        }
        ans[Q[i].second]=N*Q[i].first+ss;
    }
    for(i=0;i<T;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}