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
int main(){
	T=read();
	while(T--)
	{
		int n,m;
		n=read();
		m=read();
		int cnt=0;
		for(int i=n;i>m;i--)cnt++;
		for(int i=m-1;i>=(m+1)/2;i--)cnt++;
		cout<<cnt<<"\n";
		for(int i=n;i>m;i--)cout<<i<<" ";
		for(int i=m-1;i>=(m+1)/2;i--)cout<<i<<" ";
		puts("");
	}
	return 0;
}