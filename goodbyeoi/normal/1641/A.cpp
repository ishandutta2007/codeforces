#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M],x;
map<int,int>t;

signed main()
{
	WT
	{
		n=read(),x=read();int res=0;t.clear();
		for (int i=1;i<=n;i++)t[a[i]=read()]++;
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)
			if (t[a[i]])
			{
				t[a[i]]--;
				if (t[a[i]*x])t[a[i]*x]--;
				else res++;
			}
		cout<<res<<'\n';
	}
	return 0;
}