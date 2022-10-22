#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int x1=get(),y1=get(),z1=get(),x2=get(),y2=get(),z2=get();
		int ans=min(z1,y2)*2;z1-=ans>>1,y2-=ans>>1;
		int tmp=min(z1,z2);z1-=tmp,z2-=tmp;tmp=min(y1,y2);y1-=tmp,y2-=tmp;
		tmp=min(z2,x1),z2-=tmp,x1-=tmp;if(z2&&y1)tmp=min(z2,y1),z2-=tmp,y1-=tmp,ans-=tmp*2;
		cout<<ans<<'\n';
	}
	return 0;
}