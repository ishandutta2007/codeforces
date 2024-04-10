#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i,cnt;
LL A[1234];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    A[N++]=0;
    sort(A,A+N);
    for(i=1;i<N;i++)
        if(A[i]!=A[i-1])
            cnt++;
    cout<<cnt<<endl;
    return 0;
}