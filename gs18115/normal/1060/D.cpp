#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL N,i,sum;
LL A[1234567],B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i]>>B[i];
    sort(A,A+N);
    sort(B,B+N);
    sum=N;
    for(i=0;i<N;i++)
        sum+=max(A[i],B[i]);
    cout<<sum<<endl;
    return 0;
}