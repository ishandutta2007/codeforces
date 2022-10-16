#include<bits/stdc++.h>
using namespace std;
char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
#define getchar gc
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
const int xx=1e5+5;
int t[xx];
int main(){
//	freopen("a.in","r",stdin);
	int T=read();
	while(T--)
	{
		int n;
		n=read();
		if(n%4==0)cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
		if(n%4==1)cout<<n/4*2<<" "<<n/4*2<<" "<<1<<"\n";
		if(n%4==2)cout<<n/4*2<<" "<<n/4*2<<" "<<2<<"\n";
		if(n%4==3)cout<<n/4*2+1<<" "<<n/4*2+1<<" "<<1<<"\n";
		n=read();
	}
	return 0;
}