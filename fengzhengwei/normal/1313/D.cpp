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
const int xx=1e5+5;
int n,m,k;
struct node
{
	int l,id;
	bool operator<(const node&w)const
	{
		return l==w.l?id<w.id:l<w.l;
	}
}e[xx<<1];
int f[257];
int vis[8];
int js(int x)
{
	int tot=0;
	for(int i=0;i<8;i++)if(x&(1<<i))tot++;
	return (tot&1);
}
int ss[300];
int main(){
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		int a,b;
		a=read();
		b=read();
		e[i*2-1].l=a;
		e[i*2-1].id=i;
		e[i*2].l=b+1;
		e[i*2].id=-i;
	}
	for(int i=0;i<=280;i++)ss[i]=js(i);
	memset(f,-0x7f,sizeof(f));
	sort(e+1,e+n*2+1);
	e[n*2+1].l=e[n*2].l;
	f[0]=0;
//	cout<<ss[4]<<endl;
	for(int j=1;j<=n*2;j++)
	{
		int id=e[j].id;
		int len=e[j+1].l-e[j].l;
//		cout<<len<<endl;
//		cout<<id<<" "<<e[j<<"weqeq"<<endl;
		if(id>0)// 
		{
			for(int i=0;i<8;i++)
			{
				if(!vis[i])
				{
					vis[i]=id;
					id=i;
					break;
				}
			}
			for(int i=256-1;i>=0;i--)// 
			{
				if(!(i&(1<<id)))f[i+(1<<id)]=f[i]+ss[i+(1<<id)]*len;
				f[i]=f[i]+ss[i]*len;
			}
		}
		else 
		{
			for(int i=0;i<8;i++)
			{
				if(vis[i]==-id)
				{
					vis[i]=0;
					id=i;
					break;
				}
			}
			for(int i=0;i<256;i++)// 
			{
				if(i&(1<<id))f[i-(1<<id)]=max(f[i-(1<<id)],f[i]+ss[i-(1<<id)]*len),f[i]=-2147483647;
				else f[i]=f[i]+ss[i]*len;
			}
		}
//    	puts("!!!");
//    	cout<<j<<'\n';
//		for(int i=0;i<256;i++)
//		{
//			if(f[i]>=0)cout<<i<<" "<<f[i]<<"\n";
//		}
//		puts("");
	}
	cout<<f[0]<<endl;
	return 0;
}