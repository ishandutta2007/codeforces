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
#define task "976B"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
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
int m,n,k,r,f;
main()
{
    //freopen(task".inp","r",stdin);
    cin>>m>>n>>k;
    if(m>k) return cout<<k+1<<" "<<1,0;
    if(k==m) return cout<<m<<" "<<2,0;
    k-=m;
    f=k/(n-1);
    r=k%(n-1);
    if(f&1) return cout<<m-f<<" "<<n-r,0;
    else return cout<<m-f<<" "<<2+r,0;
}