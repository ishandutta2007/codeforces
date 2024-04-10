#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1e5+5;
int a[xx],n;
int B1=315,bel[xx];
struct node{int l,r,id;bool operator<(const node&w)const{return bel[l]==bel[w.l]?bel[l]&1?r<w.r:r>w.r:bel[l]<bel[w.l];};}q[xx];
int t[xx],cs[xx],T[xx];
ll res[xx];
//sqrt 
int B2=1288;
multiset<int>s;
void ad(int x){cs[t[x]]--,t[x]++,cs[t[x]]++;}
void er(int x){cs[t[x]]--,t[x]--,cs[t[x]]++;}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),bel[i]=(i-1)/B1+1;
	int m=read();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);
	int l=1,r=0;cs[0]=n;
	while(r<=n)ad(a[++r]);
	vector<int>v;
	for(int i=1;i<=100000;i++)if(t[i]>B2)v.push_back(i);
	ll ans=0;
	for(int I=1;I<=m;I++)
	{
		ans=0;
		while(r<q[I].r)ad(a[++r]);
		while(l>q[I].l)ad(a[--l]);
		while(r>q[I].r)er(a[r--]);
		while(l<q[I].l)er(a[l++]);
		for(int i=1;i<=B2;i++)T[i]=cs[i];
		int rem=-1;
		multiset<int>s;
		for(auto it:v)if(t[it]>B2)s.insert(t[it]);
//		for(auto it:s)cout<<it<<" ";puts("");
		for(int i=1;i<=B2;i++)
		{
			if(rem!=-1&&T[i])
			{
				T[i]--;
				int to=i+rem;
				ans+=to;
				if(to>B2)s.insert(to);
				else T[to]++;
				rem=-1;
			}
			if(T[i])
			{
				int mgs=T[i]/2;
				ans+=1ll*(i+i)*mgs;
				if(i+i>B2)
					while(mgs--)s.insert(i+i);
				else T[i+i]+=mgs;
				if(T[i]&1)rem=i;
			}
		}
		if(rem!=-1)s.insert(rem);
		while(s.size()!=1)
		{
			ll a=*s.begin();
			s.erase(s.begin());
			a+=*s.begin();
			s.erase(s.begin());
			ans+=a;
			s.insert(a);
		}
		res[q[I].id]=ans;
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<"\n";
	pc('1',1);
	return 0;
}