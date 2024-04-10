#include<bits/stdc++.h>
#define ll long long 
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
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=1e5+5,B=500;
int n,bel[xx],tag[xx],isbf[xx],t[xx];
//tagtag 
//ttag 
int L[xx],R[xx];
ll s[xx],m[xx],r[xx];
void down(int id)
{
	int l=L[id],r=R[id];
	for(int i=l;i<=r;i++)t[i]+=tag[id];
	tag[id]=0;
}
ll solve(int l,int rr)//  
{
	down(bel[l]);
	isbf[bel[l]]=1;
	ll ans=0;
	for(int i=l;i<=rr;i++)s[i]=min(m[i],s[i]+t[i]*r[i]),ans+=s[i],s[i]=t[i]=0;
	return ans;
}
int id[xx],lim[xx];
ll sm[xx],sr[xx];
ll ef(int idd)
{
	int l=L[idd],r=R[idd],ans=l-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(lim[id[mid]]<=tag[idd])ans=mid,l=mid+1;
		else r=mid-1;
	}
	int w=tag[idd];
	tag[idd]=0;
	return sm[ans]-sm[L[idd]-1]+(sr[R[idd]]-sr[ans])*w;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)bel[i]=(i-1)/B+1,(!L[bel[i]]?L[bel[i]]=i:0),R[bel[i]]=i;
	for(int i=1;i<=n;i++)s[i]=read(),m[i]=read(),r[i]=read();
	for(int i=1;i<=n;i++)!r[i]?lim[i]=1e9:lim[i]=(m[i]+r[i]-1)/r[i];
	for(int i=1;i<=bel[n];i++)isbf[i]=1;
	for(int i=1;i<=n;i++)id[i]=i;
	for(int i=1;i<=bel[n];i++)
		sort(id+L[i],id+R[i]+1,[&](int a,int b){return lim[a]<lim[b];});
	for(int i=1;i<=n;i++)sm[i]=sm[i-1]+m[id[i]];
	for(int i=1;i<=n;i++)sr[i]=sr[i-1]+r[id[i]];
	int q=read();
	int lst=0;
	while(q--)
	{
		int now=read();
		for(int i=1;i<=bel[n];i++)tag[i]+=now-lst;
		lst=now;
		int l=read(),r=read();
		if(bel[l]==bel[r])cout<<solve(l,r)<<"\n";
		else 
		{
			ll ans=0;
			ans+=solve(l,R[bel[l]]),ans+=solve(L[bel[r]],r);
			for(int i=bel[l]+1;i<bel[r];i++)
			{
				if(isbf[i])ans+=solve(L[i],R[i]),isbf[i]=0;
				else ans+=ef(i);
			}
			cout<<ans<<"\n";
		}
	}
	pc('1',1);
	return 0;
}