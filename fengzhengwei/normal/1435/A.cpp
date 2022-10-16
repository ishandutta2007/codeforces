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
int T;
int a[10005];
int main(){
	T=read();
	while(T--)
	{
		int n;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n;i++)
			if(i&1)
			{
				printf("%d ",a[i+1]);
			}
			else printf("%d ",-a[i-1]);
		puts("");
		
	}
	return 0;
}