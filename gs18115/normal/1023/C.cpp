#include<iostream>
#include<stack>
using namespace std;
int N,K;
char S[234567];
int cnt,i;
bool chk[234567];
stack<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    cin>>S;
    cnt=N;
    for(i=0;i<N;i++)
    {
        if(cnt<=K)
            break;
        else if(S[i]=='(')
            s.push(i);
        else
        {
            chk[s.top()]=true;
            chk[i]=true;
            s.pop();
            cnt-=2;
        }
    }
    for(i=0;i<N;i++)
        if(!chk[i])
            cout<<S[i];
    cout<<endl;
    return 0;
}