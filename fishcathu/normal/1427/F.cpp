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
const int N=1210;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

pii a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),s=n*6;
    for(int i=1;i<=s;++i)a[i][0]=i;
    for(int i=s>>1;i--;a[read()][1]=1);
    for(int T=n<<1;T--;s-=3)
    {
        int i=1;
        while(i<=s-3&&(!(i%3)||a[i][1]==a[i+1][1]))++i;
        for(i+=3;i<=s&&(a[i][1]+T&1||a[i-1][1]^a[i][1]||a[i-2][1]^a[i][1]);++i);
        if(i>s)for(i=3;a[i][1]+T&1||a[i-1][1]^a[i][1]||a[i-2][1]^a[i][1];++i);
        cout<<a[i-2][0]<<' '<<a[i-1][0]<<' '<<a[i][0]<<'\n';
        while(++i<=s)a[i-3]=a[i];
    }
}