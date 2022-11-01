#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=2e5;
int n,f[N+1],s[N+1],t[N+1];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("f.inp","r",stdin);
    read(n);
    forinc(i,1,n)
    {
        int x;read(x);
        s[x]++;
    }
    forinc(i,1,N) if(s[i])
    {
        if(s[i-1]>1) f[i]=f[i-1]+s[i],t[i]=t[i-1];
        else f[i]=s[i]+s[i-1],t[i]=i-1;
    }
    int r=1,l=1;
    forinc(i,1,N) if(f[i]>f[r]) r=i,l=t[i];
    cout<<f[r]<<"\n";
    forinc(i,l,r) forinc(j,1,s[i]/2) cout<<i<<" ";
    fordec(i,r,l) forinc(j,1,s[i]-s[i]/2) cout<<i<<" ";
}