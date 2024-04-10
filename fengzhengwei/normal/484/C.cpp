#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}/*
const int xx=505;
int n;
struct nod
{
	int id[xx];
	void init()
	{
		for(int i=1;i<=n;i++)id[i]=i;
	}
	void print()
	{
		for(int i=1;i<=n;i++)cout<<id[i]<<" ";
		puts("");
		puts("");
	}
}now,ls[xx];*/
const int xx=1e6+5;
char s[xx];
int n,to[xx],dp[xx],cr[xx];
int get(int x)
{
	if(!x)return 0;
	
	if(cr[x]&&!dp[x])return 1e9;
	if(dp[x])return dp[x];
	cr[x]=1;
	return dp[x]=1+get(to[x]);
}
int f[xx][21];
void run(int len,int d)
{
	int tt=0;//-1 
	for(int i=1;i<min(len+1,d+1);i++)
		for(int j=i;j<=len;j+=d)to[j]=tt++;
	dp[0]=0;
	for(int i=1;i<=len;i++)dp[i]=cr[i]=0;
	for(int i=1;i<=len;i++)dp[i]=get(i);
//	for(int i=1;i<=len;i++)cout<<i<<" "<<to[i]<<" "<<dp[i]<<"!!\n";
	for(int i=1;i<=len;i++)f[i][0]=to[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
}
int jp(int x,int y)
{
	for(int j=20;j>=0;j--)if(y>>j&1)x=f[x][j];
	return x;
}
char c[xx];
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int m=read();
	while(m--)
	{
		int k=read(),d=read(),num=0;
		//d=1 
		if(d==1||k==1)
		{
			cout<<s+1<<"\n";
			continue;
		}
		// 
		run(k,d);
		int id=k,re=0,I=0;
		while(id)id=to[id],re++;
		for(int i=k;i<=n;i++)if(i-k+re<=n-k+1)c[i-k+re]=s[i];else {I=i;break;}
//		cout<<I<<"!!\n";
		//1~re-1 
		for(int i=1;i<k;i++)if(dp[i]<=n-k+1)c[dp[i]]=s[i];//dp0 
		//n-k+re+1~n 
		//n-k+1~n
		// 
		// 
		for(int i=1;i<k;i++)if(dp[i]>n-k+1)c[n-k+1+jp(i,n-k+1)]=s[i];
//		,cerr<<i<<" "<<jp(i,n-k+1)<<"!ASD\n";
		//re 
		int ce=min(re-1,n-k+1);
		for(int i=I;i<=n;i++)c[n-k+1+jp(k,ce--)]=s[i];
		for(int i=1;i<=n;i++)s[i]=c[i];
		cout<<s+1<<"\n";
	}
/*
	n=read();
	now.init();
	int top=0;
	ls[top]=now;
	while(1)
	{
		int op=read();
		if(op==0)top--;
		else 
		{
			int l=read(),r=read(),d=read();
			ls[top+1]=ls[top];
			int tt=l-1;
			for(int j=l;j<min(r+1,l+d);j++)
				for(int i=j;i<=r;i+=d)
					ls[top+1].id[++tt]=ls[top].id[i];
			++top;
		}
		ls[top].print();
	}*/
	pc('1',1);
	return 0;
}