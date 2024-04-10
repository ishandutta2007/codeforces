#include<bits/stdc++.h>
#define ll long long
#define LL __int128
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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=4e5+5;
int n,q,ans[xx],dl[xx],a[xx];
namespace s1
{
	int mn[xx<<2];
	void build(int k,int l,int r)
	{
		if(l==r)return mn[k]=a[l],void();
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		mn[k]=min(mn[k<<1],mn[k<<1|1]);
	}
	int ask(int k,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return mn[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return min(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
}
namespace s2
{
	// 
	// 
	//m(-2*id+val),m(-2*id-val),mval,m-val 
	//m(2*id+val),m(2*id-val),mval,m-val 
	struct nod{int m1,m2,m3,m4;}e[xx<<2];
	nod upd(const nod&a,const nod&b){return {min(a.m1,b.m1),min(a.m2,b.m2),min(a.m3,b.m3),min(a.m4,b.m4)};}
	void cg(int k,int l,int r,int x,const nod&c)
	{
		if(l==r)return e[k]=c,void();
		int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,c);
		else cg(k<<1|1,mid+1,r,x,c);
		e[k]=upd(e[k<<1],e[k<<1|1]);
	}
	const int inf=1e9;
	nod ask(int k,int l,int r,int x,int y)
	{
		if(x>y)return {inf,inf,inf,inf};
		if(x<=l&&r<=y)return e[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
}
int r1[xx],c1[xx],r2[xx],c2[xx],tmn[xx];
vector<int>v[xx];
int stk[xx],top;
void run()
{
	top=0;
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<"@#\n";
		while(top&&a[stk[top]]>a[i])top--;
		stk[++top]=i;
		s2::cg(1,1,n,top,{-2*i+a[i],-2*i-a[i],a[i],-a[i]});
		for(auto it:v[i])
		{
			int pos=c2[it];
			int l=1,r=top,an=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[stk[mid]]>=pos)an=mid,r=mid-1;
				else l=mid+1;
			}
//		cerr<<i<<" "<<it<<"@#\n";
			//an~top -> val-pos.
			//1~an-1 -> pos-val.
			//end. 
			
			l=1,r=top;int aed=top+1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(a[stk[mid]]>=(r1[it]<i?c1[it]:tmn[it]))aed=mid,r=mid-1;
				else l=mid+1;
			}
			
			if(r1[it]<i)
			{
//				cerr<<"ASD\n";
				l=1,r=top;
				int _ans=0;
				while(l<=r)
				{
					int mid=l+r>>1;
					if(stk[mid]>=r1[it])_ans=mid,r=mid-1;
					else l=mid+1;
				}
				//_ans~top -> id 
				//1~_ans-1 -> nid->r1[it]
				//ber 
				
				//end 
				
				
//				cerr<<c1[it]<<"@@\n";
//				cerr<<aed<<' '<<top<<' '<<a[stk[top]]<<" "<<a[i]<<" "<<a[stk[top]]<<"!\n";
				
				
				if(_ans<an)
				{
//					puts("");
					ans[it]=min(ans[it],-pos+s2::ask(1,1,n,an,top).m3+1);
					ans[it]=min(ans[it],pos+s2::ask(1,1,n,_ans,an-1).m4+1);
					ans[it]=min(ans[it],2*r1[it]+pos+s2::ask(1,1,n,aed,_ans-1).m2+1);
					ans[it]=min(ans[it],2*r1[it]+pos+s2::ask(1,1,n,1,min(aed,_ans)-1).m2);
				}
				else 
				{
//					cerr<<"@@\n";
					ans[it]=min(ans[it],-pos+s2::ask(1,1,n,_ans,top).m3+1);
					if(an<=aed)
					ans[it]=min(ans[it],2*r1[it]-pos+s2::ask(1,1,n,aed,_ans-1).m1+1),
					ans[it]=min(ans[it],2*r1[it]-pos+s2::ask(1,1,n,an,min(_ans,aed)-1).m1);
					else 
					ans[it]=min(ans[it],2*r1[it]-pos+s2::ask(1,1,n,an,_ans-1).m1+1);
					
//					cerr<<ans[it]<<" "<<an<<" "<<_ans<<"!\n";
					ans[it]=min(ans[it],2*r1[it]+pos+s2::ask(1,1,n,aed,an-1).m2+1);
					ans[it]=min(ans[it],2*r1[it]+pos+s2::ask(1,1,n,1,min(aed,an)-1).m2);
				}
			}
			else 
			{
				
//				cerr<<i<<" "<<r1[it]<<' '<<it<<" "<<aed<<" "<<an<<"@\n";
				if(an<=aed)
				ans[it]=min(ans[it],2*i-pos+s2::ask(1,1,n,aed,top).m1+1),
				ans[it]=min(ans[it],2*i-pos+s2::ask(1,1,n,an,aed-1).m1),
				ans[it]=min(ans[it],2*i+pos+s2::ask(1,1,n,1,an-1).m2);
				else 
				ans[it]=min(ans[it],2*i-pos+s2::ask(1,1,n,an,top).m1+1),
				ans[it]=min(ans[it],2*i+pos+s2::ask(1,1,n,aed,an-1).m2+1),
				ans[it]=min(ans[it],2*i+pos+s2::ask(1,1,n,1,aed-1).m2);
				
				//end 
			}
		}
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	s1::build(1,1,n);
	q=read();
	for(int i=1;i<=q;i++)ans[i]=1e9;
	for(int i=1;i<=q;i++)
	{
		r1[i]=read(),c1[i]=read(),r2[i]=read(),c2[i]=read();
		ans[i]=min(ans[i],1+c2[i]),dl[i]=abs(r1[i]-r2[i]);//home 
		tmn[i]=min(c1[i],s1::ask(1,1,n,min(r1[i],r2[i]),max(r1[i],r2[i])));
		ans[i]=min(ans[i],abs(c2[i]-min(c1[i],s1::ask(1,1,n,min(r1[i],r2[i]),max(r1[i],r2[i])))));//no 
		// 
		v[r2[i]].push_back(i);
	}
	run();
	for(int i=1;i<=n;i++)v[i].clear();
	reverse(a+1,a+n+1);
	for(int i=1;i<=q;i++)
		r1[i]=n-r1[i]+1,r2[i]=n-r2[i]+1,v[r2[i]].push_back(i);
	run();
//	for(int i=1;i<=q;i++)cout<<ans[i]+dl[i]<<"\n";
//	exit(0);
	for(int i=1;i<=q;i++)cout<<ans[i]+dl[i]<<"\n";
	pc('1',1);
	return 0;
}