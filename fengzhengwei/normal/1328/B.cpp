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
void print()
{
	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a,b;
		a=read();
		b=read();
		int l=1;
		int r=1e6;
		while(l<r)
		{
			int mid=l+r>>1;
			if(mid*(mid-1)/2>=b)r=mid;
			else l=mid+1;
		}
		int j=l;
		for(j=1;j<=a;j++)
		{
			if(j*(j-1)/2>=b)break;
		}
		b-=(j-2)*(j-1)/2;
		for(int k=1;k<=((a-j)/100);k++)print();
		for(int k=1;k<=(a-j)%100;k++)
		{
			
			printf("a");
		}
		printf("b");
		for(int k=1;k<=(j-b-1)/100;k++)print();
		for(int k=1;k<=(j-b-1)%100;k++)
		{
			printf("a");
		}
		printf("b");
		for(int k=1;k<=(b-1)/100;k++)print();
		for(int k=1;k<=(b-1)%100;k++)
		{
			printf("a");
		}
		printf("\n");
	}
	return 0;
}