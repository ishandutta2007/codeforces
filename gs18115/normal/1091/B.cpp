#include<iostream>
#include<vector>
#include<algorithm>
#define aa first
#define bb second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i;
PL A[123456],B[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i].aa>>A[i].bb;
    for(i=0;i<N;i++)
        cin>>B[i].aa>>B[i].bb;
    sort(A,A+N);
    sort(B,B+N,greater<PL>());
    cout<<A[0].aa+B[0].aa<<' '<<A[0].bb+B[0].bb<<endl;
    return 0;
}