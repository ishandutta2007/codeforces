#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL i,j,N;
string S[1234567];
LL P,cnt;
map<LL,LL>s;
LL mini,d,D;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>S[i];
        mini=d=D=0;
        for(j=0;j<S[i].size();j++)
        {
            if(S[i][j]=='(')
                d++;
            else
                D++;
            mini=min(d-D,mini);
        }
        if(d-D<=mini||mini==0)
            s[d-D]++;
    }
    for(auto I:s)
    {
        if(I.first==0)
        {
            P=I.second/2;
            s[0]-=P*2;
            cnt+=P;
            continue;
        }
        P=min(s[-I.first],I.second);
        s[-I.first]-=P;
        s[I.first]-=P;
        cnt+=P;
    }
    cout<<cnt<<endl;
    return 0;
}