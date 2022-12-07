//AFO countdown:11 Days
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

string s;

signed main()
{
	WT
	{
		int n=read();cin>>s;
		int f=1;
		for (int i=0;i+1<n;i++)
			if (s[i]!=s[i+1]){f=0,cout<<i+1<<' '<<i+2<<endl;break;}
		if (f){puts("-1 -1");continue;}
	}
	return 0;
}