#include<iostream>
using namespace std;
int N,a,b,i,mini,minj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    if(N==1)
        cout<<-1;
    else if(N==2)
    {
        cin>>a>>b;
        if(a==b)
            cout<<-1;
        else
            cout<<1<<'\n'<<1;
    }
    else
    {
        mini=999999;
        minj=0;
        for(i=1;i<=N;i++)
        {
            cin>>a;
            if(mini>a)
                mini=a,minj=i;
        }
        cout<<1<<'\n'<<minj;
    }
    return 0;
}