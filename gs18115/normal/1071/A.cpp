#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;
LL N,M,i,S,X,cnt;
bool chk[1234567];
stack<LL>stk;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=1;S<=N+M;i++)
        S+=i;
    X=i-2;
    if(N==0)
    {
        cout<<0<<endl<<endl;
        cout<<X<<endl;
        for(i=1;i<=X;i++)
            cout<<i<<' ';
        cout<<endl;
    }
    else
    {
        S=0;
        for(i=X;i>0;i--)
        {
            if(i+S>N)
                break;
            cnt++;
            chk[i]=true;
            S+=i;
        }
        if(N>S&&!chk[N-S])
            cout<<cnt+1<<endl;
        else
            cout<<cnt<<endl;
        S=0;
        for(i=X;i>0;i--)
        {
            if(i+S>N)
                break;
            stk.push(i);
            chk[i]=true;
            S+=i;
        }
        if(N>S&&!chk[N-S])
        {
            stk.push(N-S);
            chk[N-S]=true;
            cnt++;
        }
        while(!stk.empty())
        {
            cout<<stk.top()<<' ';
            stk.pop();
        }
        cout<<endl<<X-cnt<<endl;
        for(i=1;i<=X;i++)
            if(!chk[i])
                cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}