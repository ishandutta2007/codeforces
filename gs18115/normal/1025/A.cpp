#include<iostream>
using namespace std;
int N,i;
bool chk[1234567];
char S[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N<2)
        return cout<<"Yes"<<endl,0;
    cin>>S;
    for(i=0;i<N;i++)
    {
        if(chk[S[i]])
            return cout<<"Yes"<<endl,0;
        chk[S[i]]=true;
    }
    return cout<<"No"<<endl,0;
}