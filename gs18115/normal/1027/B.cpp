#include<iostream>
using namespace std;
bool flag;
long long N,Q,X,Y,ans,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>Q;
    flag=N&1;
    n=(N*N+1)>>1;
    while(Q--)
    {
        cin>>X>>Y;
        X--;
        Y--;
        if((X+Y)&1)
        {
            if(flag)
            {
                if(X&1)
                    ans=((X>>1)*N)+(N>>1)+(Y>>1)+1+n;
                else
                    ans=((X>>1)*N)+(Y>>1)+1+n;
            }
            else
                ans=(X*(N>>1))+(Y>>1)+1+n;
        }
        else
        {
            if(flag)
            {
                if(X&1)
                    ans=((X>>1)*N)+(N>>1)+(Y>>1)+2;
                else
                    ans=((X>>1)*N)+(Y>>1)+1;
            }
            else
                ans=(X*(N>>1))+(Y>>1)+1;
        }
        cout<<ans<<endl;//'\n';
    }
    return 0;
}