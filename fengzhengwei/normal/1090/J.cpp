// LUOGU_RID: 90453828
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
char ST;
char A[xx],B[xx],C[xx];
int nxt[xx],lc[xx],ct[xx],mn[xx],tt;
char ED;
int main(){
//	cout<<sizeof(f)/1024/1024<<"$\n";// 191 
//	freopen("a.in","r",stdin);
	
	scanf("%s",A+1);
	scanf("%s",B+1);
	int n=strlen(A+1),m=strlen(B+1);
	for(int i=1;i<=m;i++)C[i]=B[i];
	for(int i=1;i<=n;i++)C[i+m]=A[i];
	int mx=0,mid=0;
	// 
	for(int i=2;i<=n+m;i++)
	{
		if(mid+mx-1>=i)lc[i]=min(lc[i-mid+1],mid+mx-1-i+1);
		while(C[i+lc[i]]==C[1+lc[i]])++lc[i];
		if(i+lc[i]>mid+mx)mid=i,mx=lc[i];
	}
	for(int i=2,p=0;i<=n+m;i++)
	{
		while(p&&C[p+1]!=C[i])p=nxt[p];
		if(C[p+1]==C[i])++p;
		nxt[i]=p;
	}
	for(int i=1;i<=n+m;i++)
	{
		mn[i]=i;
		if(mn[nxt[i]])mn[i]=min(mn[nxt[i]],mn[i]);
	}
	for(int i=1;i<=m;i++)ct[i-nxt[i]]++;
	for(int i=n+m;i>=1;i--)ct[i]+=ct[i+1];
	ll ans=0;
	// 
//	cerr<<ct[1]<<" "<<ct[2]<<" "<<ct[3]<<"\n";
	for(int i=1;i<=n;i++)
	{
		int l=lc[i+m+1];
//		cerr<<l<<"@\n";
		ans+=ct[l+1];
	}
//	cerr<<ans<<"\n";
	for(int i=1;i<=n;i++)
	{
//		if((mn[i+m]<i))cerr<<i<<" "<<nxt[i+m]<<"!!\n";
		ans+=(mn[i+m]<min(i,m+1));
	}
	
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}