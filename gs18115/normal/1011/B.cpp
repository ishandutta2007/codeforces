#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> > >PQ;
pair<int,int>X;
int FI,SE,N,M,i,A;
int cnt[1234],CNT[1234];
int MI=99999999;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(i=0;i<M;i++)
    {
        cin>>A;
        cnt[A-1]++;
    }
    for(i=0;i<100;i++)
        PQ.push(make_pair(cnt[i],i));
    for(i=0;i<N;i++)
    {
        X=PQ.top();
        PQ.pop();
        FI=X.first;
        SE=X.second;
        CNT[SE]++;
        PQ.push(make_pair(cnt[SE]/(CNT[SE]+1),SE));
        MI=min(MI,FI);
    }
    cout<<MI<<endl;
    return 0;
}