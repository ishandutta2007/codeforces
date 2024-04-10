#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <climits>
#include <random>
#include <chrono>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
inline long long in(){long long x=0;char c=getchar();bool neg=false;while(c!='-'&&('0'>c||c>'9')) c=getchar();if(c=='-') neg=true,c=getchar();while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();if(neg) x=-x;return x;}
inline void out(long long x){if(x<0) putchar('-'),x=-x;if(x>9) out(x/10);putchar(x%10+'0');}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){return l+rng()%(r-l+1);}
#define task "b"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define nd second.first
#define rd second.second
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<ii>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define _ putchar(' ')
#define __ putchar('\n')
const int N=1000010,mod=1e9+7;
int n,a[N],f[N],kq,g[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
main()
{
    //freopen("a.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(a[i]);
    f[0]=1;
    forinc(i,1,n)
    {
        forinc(j,1,sqrt(a[i])) if(a[i]%j==0)
        {
            g[j]=(g[j]+f[j-1])%mod;
            if(j*j!=a[i]) g[a[i]/j]=(g[a[i]/j]+f[a[i]/j-1])%mod;
        }
        forinc(j,1,sqrt(a[i])) if(a[i]%j==0)
        {
            f[j]=(f[j]+g[j])%mod;
            if(j*j!=a[i]) f[a[i]/j]=(f[a[i]/j]+g[a[i]/j])%mod;
            g[j]=g[a[i]/j]=0;
        }
    }
    forinc(i,1,n) kq=(kq+f[i])%mod;
    cout<<kq;
}