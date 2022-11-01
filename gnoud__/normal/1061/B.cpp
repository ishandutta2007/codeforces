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
const int N=100010;
int n,m,ma,sum,K;
int a[N];
main()
{
    //freopen(task".inp","r",stdin);
    cin>>n>>m;
    forinc(i,1,n) cin>>a[i],ma=max(ma,a[i]),sum+=a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int it=ma;
    forinc(i,1,n)
    {
        if(a[i]>=it) K++,it--;
        else
        {
            K+=it-a[i]+1;
            it=a[i]-1;
        }
    }
    cout<<sum-K-max(0ll,it);
}