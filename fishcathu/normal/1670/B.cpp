#include<bits/stdc++.h>
using namespace std;
const int N=123;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

bool b[N];
void solve()
{
    read();
    string a=read<string>();
    for(int i=97;i<N;++i)b[i]=0;
    for(int m=read();m--;b[read<char>()]=1);
    int ans=0;
    for(int s=0;char x:a)
    {
        if(b[x])cmax(ans,s),s=0;
        ++s;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}