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
int t[10006];
int main(){
	int T;
	T=read();
	while(T--)
	{
		int n;
		n=read();
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++)
		{
			t[read()]++;
		}
		int ans1;
		for(int i=0;i<=101;i++)
		{
			if(!t[i])
			{
				ans1=i;
				break;
			}
			else t[i]--;
		}
		int ans2;
		for(int i=0;i<=101;i++)
		{
			if(!t[i])
			{
				ans2=i;break;
			}
			else t[i]--;
		}
		cout<<ans1+ans2<<endl;
	}
	return 0;
}