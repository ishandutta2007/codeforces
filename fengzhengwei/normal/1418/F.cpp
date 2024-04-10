#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
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
multiset<int>s;
vector<int>fac[xx];
int n,m,ct[xx],cs[xx];
void in(int x){for(auto &it:fac[x])if((++cs[it])==1)s.insert(it);}
void er(int x){for(auto &it:fac[x])if((cs[it]--)==1)s.erase(it);}
struct qu{int A,B,C,D;};
vector<qu>out;
ll L,R;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read(),L=read(),R=read();
	for(int i=1;i<=max(n,m);i++)
		for(int j=i;j<=max(n,m);j+=i)++ct[j];
	for(int i=1;i<=max(n,m);i++)fac[i].resize(ct[i]),ct[i]=0;
	for(int i=1;i<=max(n,m);i++)
		for(int j=i;j<=max(n,m);j+=i)fac[j][ct[j]++]=i;
	#define fi first
	#define se second
	int l=1,r=0;
	for(int i=n;i>=1;i--)
	{
		while((r+1)<=m&&1ll*(r+1)*i<=R)in(++r);
		while(l<=r&&1ll*l*i<L)er(l++);
		int ans=-1;
		for(auto &it:fac[i])
		{
			auto ty=s.upper_bound(it);
			if(ty==s.end()||1ll*i/it*(*ty)>n);
			else 
			{
				int fi=*ty,se=((l-1)/fi+1)*fi;
				out.push_back({i,se,i/it*fi,se/fi*it});
				ans=0;
				break;
			}
		}
		if(ans==-1)out.push_back({-1});
	}
	reverse(out.begin(),out.end());
	for(auto &it:out)if(it.A==-1)cout<<-1<<"\n";else cout<<it.A<<" "<<it.B<<" "<<it.C<<" "<<it.D<<"\n";
	pc('1',1);
	return 0;
}