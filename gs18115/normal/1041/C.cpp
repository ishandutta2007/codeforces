#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
priority_queue<PL,vector<PL>,greater<PL> >pq;
LL N,M,K,i;
PL A[234567];
PL T;
LL maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }
    sort(A,A+N);
    maxi=0;
    pq.push({A[0].first,++maxi});
    A[0].first=A[0].second;
    A[0].second=maxi;
    for(i=1;i<N;i++)
    {
        T=pq.top();
        pq.pop();
        if(A[i].first-T.first<=K)
        {
            pq.push(T);
            pq.push({A[i].first,++maxi});
            A[i].first=A[i].second;
            A[i].second=maxi;
        }
        else
        {
            pq.push({A[i].first,T.second});
            A[i].first=A[i].second;
            A[i].second=T.second;
        }
    }
    cout<<maxi<<endl;
    sort(A,A+N);
    for(i=0;i<N;i++)
        cout<<A[i].second<<' ';
    cout<<endl;
    return 0;
}