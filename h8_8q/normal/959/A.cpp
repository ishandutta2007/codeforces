#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mid ((l+r)>>1)

inline int read()
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-'0';c=getchar();}
	return res;
}

int n;

signed main()
{
	n=read();
	if(n%2==1) printf("Ehab\n");
	else printf("Mahmoud\n");
	return 0;
}