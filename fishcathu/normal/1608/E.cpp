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
const int N=2E5+10;
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
vector<pii>a[3];
function<bool(pii,pii)>cmp[4]=
{
    [](pii l,pii r){return l[0]<r[0];},
    [](pii l,pii r){return l[0]>r[0];},
    [](pii l,pii r){return l[1]<r[1];},
    [](pii l,pii r){return l[1]>r[1];}
};
bool check(int p,int n,int y)
{
    auto w=a[p].begin()+n-1;
    nth_element(a[p].begin(),w,a[p].end(),cmp[y]);
    vector<pii>q[2];
    for(pii x:a[(p+1)%3])if(cmp[y](*w,x))q[0].pb(x);
    for(pii x:a[(p+2)%3])if(cmp[y](*w,x))q[1].pb(x);
    if(q[0].size()<n||q[1].size()<n)return 0;
    auto u=q[0].begin()+n-1,v=q[1].end()-n;
    for(int i=0;i<4;++i)
    {
        nth_element(q[0].begin(),u,q[0].end(),cmp[i]);
        nth_element(q[1].begin(),v,q[1].end(),cmp[i]);
        if(cmp[i](*u,*v))return 1;
    }
    return 0;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        pii x={read(),read()};
        a[read()-1].pb(x);
    }
    int l=1,r=n/3;
    while(l^r)
    {
        int m=l+r+1>>1;
        bool flag=0;
        for(int i=0;i<3;++i)for(int j=0;j<4;++j)flag|=check(i,m,j);
        flag?l=m:r=m-1;
    }
    cout<<l*3<<'\n';
}