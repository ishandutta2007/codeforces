// LUOGU_RID: 90583384
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
void wt(LL x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(LL x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int M=5,mod=1e9+7,xx=505;
int n,m;
//   
struct nod
{
	int a[xx<<1];
}e[xx];
int im[xx];
int To(char c){return c-'a';}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int iv[xx];
char s[xx];
char ED;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n>>m;
	iv[1]=1,iv[2]=3,iv[3]=2,iv[4]=4;
	// m  len  
	// n  m   
	//check  m   
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			e[j].a[i]=To(s[j]);
	}
	for(int i=1;i<=m;i++)
		e[i].a[n+i]=1;
	// m < n  n m > n  = 0 
	int lim=max(n,m);
	for(int i=1;i<=n;i++)
	{
		int cr=0;
		for(int j=1;j<=lim;j++)
			if(!im[j]&&e[j].a[i]){cr=1;swap(e[i],e[j]);break;}
		if(!cr)continue;
		im[i]=1;int D=iv[e[i].a[i]];
		for(int j=1;j<=n+m;j++)(e[i].a[j]*=D)%=M;
		for(int j=1;j<=lim;j++)
		{
			if(i==j)continue;
			if(e[j].a[i])
			{
				D=M-(e[j].a[i]);
				for(int k=1;k<=n+m;k++)(e[j].a[k]+=e[i].a[k]*D)%=M;
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		scanf("%s",s+1);
		int cr=1;
		for(int i=1;i<=lim;i++)
		{
			if(!im[i])
			{
				int re=0;
				for(int j=n+1;j<=n+m;j++)
					(re+=To(s[j-n])*e[i].a[j])%=M;
				if(re)cr=0;
			}
		}
		if(!cr)
		{
			puts("0");
			continue;
		}
		int ct=count(im+1,im+n+1,0);
		cout<<ksm(5,ct)<<"\n";
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}