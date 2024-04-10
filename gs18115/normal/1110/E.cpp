#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i;
LL A[1234567],B[1234567];
vector<LL>V1,V2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        cin>>B[i];
    if(A[0]!=B[0]||A[N-1]!=B[N-1])
        return cout<<"No"<<endl,0;
    for(i=1;i<N;i++)
    {
        V1.push_back(A[i]-A[i-1]);
        V2.push_back(B[i]-B[i-1]);
    }
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    for(i=1;i<N;i++)
        if(V1[i-1]!=V2[i-1])
            return cout<<"No"<<endl,0;
    cout<<"Yes"<<endl;
    return 0;
}