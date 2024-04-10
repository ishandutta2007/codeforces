#include<iostream>
using namespace std;
typedef long long LL;
LL N,S,A,mini,i,mm,pp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N==1)
    {
        cin>>N;
        cout<<N<<endl;
        return 0;
    }
    mini=1e18;
    for(i=0;i<N;i++)
    {
        cin>>A;
        if(A<0)
            mm++;
        else
            pp++;
        A=abs(A);
        S+=A;
        if(mini>A)
            mini=A;
    }
    if(mm>0&&pp>0)
        cout<<S;
    else
        cout<<S-mini*2;
    cout<<endl;
    return 0;
}