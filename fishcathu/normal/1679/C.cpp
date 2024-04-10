#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=1E5+10;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],b[N],c[N],d[N],n,m;
void add(int *q,int x,int k){for(;x<=n;x+=x&-x)q[x]+=k;}
int ask(int *q,int x){int y=0;for(;x;x-=x&-x)y+=q[x];return y;}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    cin>>n>>m;
    while(m--)
    {
        int k=read();
        if(k==1)
        {
            int x=read(),y=read();
            if(!a[x]++)add(c,x,1);
            if(!b[y]++)add(d,y,1);
        }
        else if(k==2)
        {
            int x=read(),y=read();
            if(!--a[x])add(c,x,-1);
            if(!--b[y])add(d,y,-1);
        }
        else
        {
            int u=read()-1,l=read()-1,v=read(),r=read();
            cout<<(ask(c,v)-ask(c,u)==v-u||ask(d,r)-ask(d,l)==r-l?"Yes":"No")<<'\n';
        }
    }
}