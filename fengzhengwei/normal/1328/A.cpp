#include<bits/stdc++.h>
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
int n,m;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a,b;
		a=read();
		b=read();
		int c=a/b;
		cout<<(b*c-a>=0?b*c-a:b*c-a+b)<<endl;
	}
	return 0;
}