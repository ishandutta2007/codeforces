#include<bits/stdc++.h>
#define ll long long 
#define dd double
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
int n,m;
// 
int lb(int x){return x&-x;};
int a[xx],b[xx];
int sum[xx],rl[xx],idsm[xx],idrl[xx];
int lsh[xx],TT;
void add(int x,int y,int id)
{
	if(rl[x]<y)rl[x]=y,idrl[x]=id;
	for(;x<=TT;x+=lb(x))
		if(sum[x]<y)sum[x]=y,idsm[x]=id;
}
int Id;
int ask(int x)
{
	int ans=0;Id=0;
	for(;x;x-=lb(x))
		if(ans<sum[x])ans=sum[x],Id=idsm[x];
	return ans;
}
int nsum[xx],f[xx],nid[xx],LS[xx],vis[xx];
void down(int x)
{
	if(!x)return;
	down(LS[x]);
	int num=a[LS[x]];
//	cout<<num<<" "<<a[x]<<"\n";
	for(int i=LS[x]+1;i<x;i++)
	{
		if(a[i]==-1)
		{
			int id=upper_bound(b+1,b+m+1,num)-b;
			if(id<=m&&b[id]<a[x])
				vis[id]=1,num=b[id],a[i]=num;
		}
	}
}
int main(){
	n=read();
	TT=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]!=-1)lsh[++TT]=a[i];
	}
	m=read();
	for(int i=1;i<=m;i++)b[i]=read(),lsh[++TT]=b[i];
	sort(lsh+1,lsh+TT+1);
	sort(b+1,b+m+1);
	TT=unique(lsh+1,lsh+TT+1)-lsh-1;
	for(int i=1;i<=n;i++)if(a[i]!=-1)a[i]=lower_bound(lsh+1,lsh+TT+1,a[i])-lsh;
	for(int i=1;i<=m;i++)b[i]=lower_bound(lsh+1,lsh+TT+1,b[i])-lsh;
	//m 
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			int mx=0,ls=0,Tid=0;
			for(int j=1;j<=m;j++)
			{
				while(ls<b[j])
				{
					if(mx<rl[ls])mx=rl[ls],Tid=idrl[ls];
					ls++;
//					mx=max(mx,rl[ls]),ls++;
				}
				nsum[j]=mx+1;// 
				nid[j]=Tid;
//				cout<<nid[j]<<"!!\n";
				
//				cout<<nsum[j]<<" "<<<<"\n";
			}
			// 
			// 
			for(int j=1;j<=m;j++)
			{
				if(rl[b[j]]<nsum[j])
					rl[b[j]]=nsum[j],idrl[b[j]]=nid[j];
			}
//				rl[b[j]]=max(rl[b[j]],nsum[j]);
		}
		else 
		{
			f[i]=max(f[i],ask(a[i]-1)+1);
			LS[i]=Id;
			int num=nsum[lower_bound(b+1,b+m+1,a[i])-b-1]+1;
			if(f[i]<num)f[i]=num,LS[i]=nid[lower_bound(b+1,b+m+1,a[i])-b-1];
//			cout<<f[i]<<" "<<nsum[2]<<" "<<(lower_bound(b+1,b+m+1,a[i])-b)<<"!!\n"; 
//			f[i]=max(f[i],nsum[lower_bound(b+1,b+m+1,a[i])-b-1]+1);
			add(a[i],f[i],i);
		}
//		cout<<i<<" "<<f[i]<<" "<<a[i]<<" "<<ask(a[i])<<"\n";
	}
	for(int i=1;i<=TT;i++)ans=max(ans,sum[i]),ans=max(ans,rl[i]);
//	cerr<<ans<<"\n";
	int cr=1;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==ans)
		{
			if(cr)down(i),cr=0;
		}
	}
	a[n+1]=TT+1;
	LS[n+1]=nid[m];
	if(cr)down(n+1);
	int L=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			while(vis[L])L++;
			a[i]=b[L];
			vis[L]=1;
		}
	}
	for(int i=1;i<=n;i++)cout<<lsh[a[i]]<<" ";
	puts("");
//	cerr<<ans<<"\n";
//	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}
/*
5
1 2 3 -1 -1 
6
6 6 3 2 5 5
1 2 2 4 5 6
*/