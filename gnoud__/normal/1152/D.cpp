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
const int N=2010;
int n,f[N][N][2],mod=1e9+7;
int F(int i,int j,int o)
{
    if(i==2*n+1) return 0;
    if(f[i][j][o]!=-1) return f[i][j][o];
    int res=0;
    if(o)
    {
        if(j) res=(res+F(i+1,j-1,0))%mod;
        if(j<2*n-i+1) res=(res+F(i+1,j+1,0))%mod;
    }
    else
    {
        if(j) res=(res+F(i+1,j-1,1))%mod;
        if(j<2*n-i+1) res=(res+F(i+1,j+1,1))%mod;
    }
    return f[i][j][o]=(res+o)%mod;
}
int main()
{
    //freopen("d.inp","r",stdin);
    cin>>n;
    reset(f,-1);
    cout<<F(1,0,0);
}