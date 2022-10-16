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
int a[104],tt;
int main(){
	int T=read();
	while(T--)
	{
		int s=read(),n=read();
		int o=s,res=0;
		tt=0;
		memset(a,0,sizeof(a));
		while(o)res+=o%10,a[++tt]=o%10,o/=10;
		if(n<=res)
		{
			for(int i=1;i<n;i++)
			{
				if(a[tt])
				{
					a[tt]--;
					cout<<'1';
					for(int j=tt-1;j>=1;j--)cout<<'0';
					cout<<" ";
					while(!a[tt])tt--;
				}
			}
			for(int i=tt;i>=1;i--)cout<<a[i];
			puts("");
			continue;
		}
//		cout<<a[1]<<" "<<a[2]<<" sss "<<a[3]<<"\n";
		int p=n;
		n-=res;
		while(n>0)
		{
			for(int i=2;i<=tt;i++)
			{
				if(a[i])
				{
					a[i]--;n++;
//					puts("qwewqe");
					int w=i-1;
					for(;w>=1;w--)
					{
						a[w]+=10;
						n-=10;
						if(n<=0||w==1)break;
						n++;
						a[w]--;
					}
					break;
				}
			}
		}
//		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"\n";
		while(!a[tt])tt--;
		int now=1;n=p;
		while(!a[now])now++;
//		cout<<n<<'\n';
		for(int i=1;i<n;i++)
		{
			if(a[now])
			{
//				cout<<now<<"!!!! \n";
				a[now]--;
				cout<<'1';
				for(int j=now-1;j>=1;j--)cout<<'0';
				cout<<" ";
				while(!a[now])now++;
			}
		}
		for(int i=tt;i>=1;i--)cout<<a[i];
		puts("");
	}
	return 0;
}