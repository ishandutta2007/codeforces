#include<iostream>
using namespace std;
int N,i;
char S[1234567];
bool flag,f;
bool F(char s)
{
    return s!='w';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    for(N=0;S[N];N++);
    for(i=0;i<N;i++)
        S[i+N]=S[i];
    flag=F(S[0]);
    int c=1,maxi=1;
    for(i=1;i<N<<1;i++)
    {
        f=F(S[i]);
        if(flag!=f)
            c++;
        else
            c=1;
        maxi=max(c,maxi);
        flag=f;
    }
    return cout<<min(N,maxi)<<endl,0;
}