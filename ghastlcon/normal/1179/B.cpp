#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef pair<int,int> pr;

const int maxn = 1e6 + 10;

inline int read()
{
	int x=0;char c=getchar();bool f=false;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=true;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return f?-x:x;
}

int n,m;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif
	
	int i,j;
	n=read();m=read();

	for(i=1;i<=n/2;i++)
	{
		vector<pr> V;
		V.resize(2*m);
		
		for(j=1;j<=m;j++) V[(j-1)<<1  ]=pr(i,j);
		for(j=1;j<=m;j++) V[(j-1)<<1|1]=pr(n-i+1,m-j+1);
		for(j=0;j<(int)V.size();j++) printf("%d %d\n",V[j].fir,V[j].sec);
	}

	if(n&1)
	{
		for(j=1;j<=m/2;j++) 
		{
			printf("%d %d\n",n/2+1,j);
			printf("%d %d\n",n/2+1,m-j+1);
		}
		if(m&1) printf("%d %d\n",n/2+1,m/2+1);
	}

	return 0;
}