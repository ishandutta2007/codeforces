#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1005+5;
char s[xx];
ll k;
int lc[xx][xx],n,m;
struct nod
{
	int l,r;
	bool operator<(const nod&w)const
	{
		int p=lc[l][w.l];
		if(p<min(r-l+1,w.r-w.l+1))return s[l+p]<s[w.l+p];
//		if(p>=max(r-l+1,w.r-w.l+1))return r-l+1<=w.r-w.l+1;
		return r-l+1<=w.r-w.l+1;
	}
}q[xx*xx];
int tt;
__int128 f[xx][xx];
const __int128 inf=1e20;
__int128 check(int L,int R)
{
	memset(f,0,sizeof(f));
	f[n+1][0]=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=n+1;i>=1;i--)f[i][j-1]+=f[i+1][j-1],f[i][j-1]=min(f[i][j-1],inf);
		for(int i=n;i>=1;i--)
		{
			int p=lc[L][i],to=-1;p=min(p,R-L+1);
			if(p>=R-L+1||s[i+p]>s[L+p])to=i+p+1;
			if(p==R-L+1)to--;
			if(to!=-1)f[i][j]+=f[to][j-1];
//			cout<<to<<"!ASd\n";
			f[i][j]=min(f[i][j],inf);
//			cout<<i<<" "<<j<<" "<<(ll)f[i][j]<<" "<<L<<" "<<R<<"^%&\n";
		}
	}
	return f[1][m];
}
int main(){
	n=read(),m=read(),k=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--)
			lc[i][j]=(s[i]!=s[j])?0:lc[i+1][j+1]+1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)q[++tt]={i,j};
	sort(q+1,q+tt+1);
	int l=1,r=tt,ans=0;
//	cout<<(ll)check(1,18)<<"\n";
//	exit(0);
	while(l<=r)
	{
		int mid=l+r>>1;
		//>=mid  
//		cout<<(ll)check(q[mid].l,q[mid].r)<<" "<<q[mid].l<<" "<<q[mid].r<<"!!\n";
		if(check(q[mid].l,q[mid].r)>=k)l=mid+1,ans=mid;
		else r=mid-1;
	}
//	cout<<ans<<"!!\n";
	for(int i=q[ans].l;i<=q[ans].r;i++)cout<<s[i];
	puts("");
	pc('1',1);
	return 0;
}