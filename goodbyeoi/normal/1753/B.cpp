#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vpi vector<pii>
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

const int M=5e5+10;
int n,a[M],k;
priority_queue<int>q;

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)q.push(-read());
	while(!q.empty())
	{
		int u=-q.top();q.pop();
//		cerr<<u<<'\n';
		if (u>=k)continue;
		if (q.size()<u)return puts("No"),0;
		for (int i=1;i<=u;i++)
			if (-q.top()!=u)return puts("No"),0;
			else q.pop();
		q.push(-u-1);
	}
	puts("Yes");
	return 0;
}