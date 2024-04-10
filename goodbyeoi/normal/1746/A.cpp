#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M],k;

void solve()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int f=0;
	for (int i=1;i<=n;i++)f|=a[i];
	if (f)puts("YES");
	else puts("NO");
}

signed main()
{
	WT solve();
	return 0;
}