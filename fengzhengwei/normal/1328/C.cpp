#include<bits/stdc++.h>
#define int long long
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
		int a;
		a=read();
		string b;
		cin>>b;
		int cnt=0; 
		for(int i=0;i<b.size();i++)
		{
			if(cnt==1)printf("0");
			else if(b[i]=='0')printf("0");
			else if(b[i]=='2')printf("1");
			else if(b[i]=='1')
			{
				printf("1");
				cnt=1;
			}
		}
		printf("\n");
		cnt=0;
		for(int i=0;i<b.size();i++)
		{
			if(cnt==1)
			{
				if(b[i]=='2')printf("2");
				if(b[i]=='0')printf("0");
				if(b[i]=='1')printf("1");
			}
			else if(b[i]=='2')printf("1");
			else if(b[i]=='0')printf("0");
			else if(b[i]=='1')printf("0"),cnt=1;
		}
		printf("\n");
	}
	return 0;
}