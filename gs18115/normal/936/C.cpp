#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
string S1,S2,t1,t2;
LL N;
vector<LL>V;
inline void oper(LL t)
{
    if(t<=0)
        return;
    V.push_back(t);
    t1=S1.substr(0,N-t);
    t2=S1.substr(N-t,t);
    reverse(t2.begin(),t2.end());
    S1=t2+t1;
    return;
}
inline void print()
{
    cout<<V.size()<<endl;
    for(LL i=0;i<V.size();i++)
        cout<<V[i]<<' ';
    cout<<endl;
    return;
}
char S3[2345],S4[2345];
LL i,j,c,M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;//>>M;
    cin>>S1;
    cin>>S2;
    for(i=0;i<N;i++)
    {
        S3[i]=S1[i];
        S4[i]=S2[i];
    }
    sort(S3,S3+N);
    sort(S4,S4+N);
    for(i=0;i<N;i++)
        if(S3[i]!=S4[i])
            return cout<<-1<<endl,0;
    if(N&1)
    {
        for(i=0;i<N;i++)
            if(S2[0]==S1[i])
                break;
        oper(N-i-1);
        c++;
    }
    for(i=0;i<N>>1;i++)
    {
        for(j=0;j<N;j++)
            if(S2[c]==S1[j])
                break;
        oper(N-j-1);
        oper(1);
        c++;
        for(j=c;j<N;j++)
            if(S2[c]==S1[j])
                break;
        oper(N-j);
        oper(N);
        oper(N-j-1);
        c++;
    }
    print();
    return 0;
}