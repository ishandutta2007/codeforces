#include<iostream>
using namespace std;
typedef long long LL;
LL i,j,N,M;
LL A[1234567],B[1234567];
LL s1,s2,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        s1+=A[i];
    }
    cin>>M;
    for(i=0;i<M;i++)
    {
        cin>>B[i];
        s2+=B[i];
    }
    if(s1!=s2)
        return cout<<-1<<endl,0;
    i=j=s1=s2=0;
    while(i<N&&j<M)
    {
        if(s1==s2&&s1>0)
        {
            s1=s2=0;
            ans++;
        }
        if(s1<s2)
            s1+=A[i++];
        else
            s2+=B[j++];
    }
    cout<<ans+1<<endl;
    return 0;
}