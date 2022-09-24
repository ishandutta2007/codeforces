#include<iostream>
using namespace std;
long long N,M;
const long long chk[6]={0,-1,-2,-3,-2,-1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    if(N>M)
    {
        N=N^M;
        M=N^M;
        N=N^M;
    }
    if(N==1)
        cout<<M+chk[M%6];
    else if(N==2&&M==2)
        cout<<0;
    else if(N==2&&M==3)
        cout<<4;
    else if(N==2&&M==7)
        cout<<12;
    else if(N&M&1)
        cout<<N*M-1;
    else
        cout<<N*M;
    cout<<endl;
    return 0;
}