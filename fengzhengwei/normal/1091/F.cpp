#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int n;
ll a[xx];
char s[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	scanf("%s",s+1);
	ll nt=0,nv=0,ng=0;
	bool tg=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			nt+=a[i];
			nv-=a[i];
			if(nv<0)nt+=tg?3*-nv:5*-nv,nv=0;
		}
		else if(s[i]=='W')tg=1,nt+=3*a[i],nv+=a[i];
		else nt+=5*a[i],nv+=a[i],ng+=a[i]*2;
		ng=min(ng,nv);
	}
	nt-=4*ng/2;
	nt-=2*(nv-ng)/2;
	cout<<nt<<"\n";
	return 0;
}