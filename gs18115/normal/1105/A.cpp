#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL N,mini,sum,I,i,j;
LL A[1234];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    mini=1e18;
    for(j=1;j<123;j++)
    {
        sum=0;
        for(i=0;i<N;i++)
            sum+=min({abs(j-A[i]),abs(j-A[i]-1),abs(j-A[i]+1)});
        if(sum<mini)
        {
            mini=sum;
            I=j;
        }
    }
    cout<<I<<' '<<mini<<endl;
    return 0;
}