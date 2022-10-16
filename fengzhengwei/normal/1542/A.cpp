#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		int t1=0,t2=0;
		for(int i=1;i<=n+n;i++)if(read()&1)t1++;else t2++;
		if(t1==t2)puts("Yes");
		else puts("No");
	}
	
	return 0;
}