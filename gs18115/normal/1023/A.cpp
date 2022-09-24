#include<iostream>
using namespace std;
int i,j,N,M;
bool flag;
char s1[234567],s2[234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    cin>>s1;
    cin>>s2;
    if(N-1>M)
        return cout<<"NO"<<endl,0;
    for(i=0;i<M;i++)
    {
        if(s1[i]=='*')
        {
            flag=true;
            break;
        }
        else if(s1[i]!=s2[i])
            return cout<<"NO"<<endl,0;
    }
    for(j=0;j<M;j++)
    {
        if(s1[N-j-1]=='*')
        {
            flag=true;
            break;
        }
        else if(s1[N-j-1]!=s2[M-j-1])
            return cout<<"NO"<<endl,0;
    }
    if(!flag&&N!=M)
        return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    return 0;
}