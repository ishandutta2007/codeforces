#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
using namespace std;
inline long long read()
{
    long long t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c<='9'&&c>='0') t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
#define int long long
char s1[200]="What are you doing while sending   ? Are you busy? Will you send   ?";
char s2[200]="What are you doing at the end of the world? Are you busy? Will you save us?";
int t,xx,yy,f[500],n,m,ff;
signed main(){
	t=read();xx=68;yy=75;f[0]=yy;s1[33]=s1[34]=s1[65]=s1[66]=34;
	for (int i=1;i<=200;i++)f[i]=f[i-1]*2+xx;
	while (t--){
		n=read();m=read();ff=0;
		if (m<n*34){putchar(s1[(m-1)%34]);continue;}
		if (n>55)m-=(n-55)*34,n=55ll;
		if (m>f[n]){putchar('.');continue;}
		for (int i=n;i>=1;i--){
			if(m<=34){ff=1;putchar(s1[m-1]);break;}
			m-=34;if (m<=f[i-1])continue;
			m=m+34-f[i-1];if (m<=66){ff=1;putchar(s1[m-1]);break;}
			m-=66;if (m<=f[i-1])continue;
			m=m+66-f[i-1];ff=1;putchar(s1[m-1]);break;
		}if (!ff)putchar(s2[m-1]);
	} 
}