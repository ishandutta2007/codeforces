#include<bits/stdc++.h>
#define ll long long
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=22;
int vis[xx];
ll pw[xx];
int re[xx];
int main(){
	pw[0]=1;
	for(int i=1;i<=10;i++)pw[i]=pw[i-1]*10;
	int T=read();
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(re,0,sizeof(re));
		ll n=read(),k=read();
		for(int i=1;i<=n;i++)vis[read()]=1;
		ll ans=0;
		vector<ll>now(19);
		for(int i=0;i<=18;i++)
		{
			now[i]=1;
			if(i)now[i]=now[i-1]*10;
			if(vis[i])now[i]=1;
		}
		k++;
		for(int i=0;i<=20;i++)
		{
			while(k>0&&re[i]<9)
			{
				re[i]++;
				k-=now[i];
			}
//			cout<<i<<" "<<now[i]<<" "<<re[i]<<" "<<k<<"\n";
			if(k<=0)
			{
				for(int j=i;j>=0;j--)
					while(k+now[j]<=0&&re[j]>=1)k+=now[j],re[j]--;
				for(int j=i;j>=0;j--)cout<<re[j];
				puts("");
				break;
			}
		}
//		cout<<ans<<"\n";
	}
	return 0;
}