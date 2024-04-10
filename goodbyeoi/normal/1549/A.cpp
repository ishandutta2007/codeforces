#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=3e5+10;
int n,m,a[M];
map<int,int>t;

signed main()
{
	WT
	{
		n=read();t.clear();
		for (int i=2;;i++)
		{
			int x=n%i;
			if (!t[x])t[x]=i;
			else {cout<<t[x]<<' '<<i<<endl;break;}
		}
	}
	return 0;
}