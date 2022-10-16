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
const int xx=205,mod=1e4+7;
char s[xx];
ll ksm(ll a,ll b)
{
	a%=mod;
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll f[xx][xx][xx];
void ad(ll &x,ll y){x+=y,x%=mod;}
int tt;
struct mat
{
	ll a[xx<<1][xx<<1];
	void cls(){for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)a[i][j]=0;}
	void cmod(){for(int i=1;i<=tt;i++)for(int j=1;j<=tt;j++)a[i][j]%=mod;}
	mat operator*(const mat&w)const
	{
		mat g;g.cls();
		for(int i=1;i<=tt;i++)
			for(int k=i;k<=tt;k++)
			{
				ll W=a[i][k];
				if(!W)continue;
				for(int j=k;j<=tt;j++)
					g.a[i][j]+=W*w.a[k][j];
			}
		g.cmod();
		return g;
	}
	mat operator+(const mat&w)const
	{
		mat g;g.cls();
		for(int i=1;i<=1;i++)
			for(int k=i;k<=tt;k++)
			{
				ll W=a[i][k];
				if(!W)continue;
				for(int j=k;j<=tt;j++)
					g.a[i][j]+=W*w.a[k][j];
			}
		g.cmod();
		return g;
	}
	void print()
	{
		puts("Out the Matrix");
		puts("");
		for(int i=1;i<=tt;i++)
		{
			for(int j=1;j<=tt;j++)
				cout<<a[i][j]<<" ";
			puts("");
		}
		puts("");
	}
}ans,zy;
//mod 
void run(int R)
{
	while(R)
	{
		if(R&1)ans=ans+zy;
		zy=zy*zy,R>>=1;
	}
}
int n,num;
int main(){
	///qd
	// 
//	freopen("a.in","r",stdin);
//	freopen("ans.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	int cr=1;
	for(int i=1;i<=n;i++)if(s[i]!=s[n-i+1])cr=0;
	f[1][n][0]=1;
	for(int l=n;l>=1;l--)
	{
		for(int i=1,j;(j=(i+l-1))<=n;i++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!f[i][j][k])continue;
				if(i==j)// 
				continue;// 
				//	ad(f[i+1][j][k],f[i][j][k]);//ai 
				else 
				{
					if(s[i]==s[j])
						ad(f[i+1][j-1][k+1],f[i][j][k]);
					else ad(f[i+1][j][k],f[i][j][k]),ad(f[i][j-1][k],f[i][j][k]);// 
				}
			}
		}
	}
	num=read();
	int ttnum=num+n;
	// 
	//1~n-1,n~n+ceil(n/2) 
	int hf=(n+1)/2;
	tt=n+hf+1;
	// 
	if(cr)ans.a[1][n+1]=1;
	else ans.a[1][1]=1;
	//1 
	for(int i=1;i<n-1;i++)zy.a[i][i+1]=1;
	for(int i=1;i<=n-1;i++)zy.a[i][i]=24;
	for(int i=n;i<tt;i++)zy.a[i][i+1]=1;
	for(int i=n;i<tt;i++)zy.a[i][i]=25;
	zy.a[tt][tt]=26;
//	zy.print();
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=n;k++)
		{
			if(!f[i+1][i][k])continue;// 
//			int rem=(ttnum+1)/2-n+k;
//			cout<<f[i+1][i][k]<<"!!\n";
			zy.a[n-k-k][tt-k]+=f[i+1][i][k];
//			if(rem<0)continue;
//			ans+=ksm((n-k)*24+k+26,rem)*f[i+1][i][k];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=n;k++)
		{
			if(!f[i][i][k])continue;// 
//			int rem=(ttnum+1)/2-n+k;
//			cout<<rem<<"!!\n";
			zy.a[n-k-k-1][tt-k-1]+=f[i][i][k];
//			if(rem<0)continue;//25 
//			ans+=ksm((n-k)*24+k+26+1,rem)*f[i][i][k];
//			cout<<i<<" "<<i<<" "<<k<<" "<<f[i][i][k]<<"!!\n";
//			ans%=mod;
		}
	}
	zy.cmod();
//	ans.print();
	run((ttnum+1)/2);
//	zy.print();
	ll res=ans.a[1][tt];
//	cout<<res<<"!\n";
//	cout<<cer<<"!!\n";
	if(ttnum&1)
	{
		//cr=1 
		if(cr==1&&(n&1));
		else {
		ans.cls(),zy.cls();
		if(cr)ans.a[1][n+1]=1;
		else ans.a[1][1]=1;
		for(int i=1;i<n-1;i++)zy.a[i][i+1]=1;
		for(int i=1;i<=n-1;i++)zy.a[i][i]=24;
		for(int i=n;i<tt;i++)zy.a[i][i+1]=1;
		for(int i=n;i<tt;i++)zy.a[i][i]=25;
	//	zy.a[tt][tt]=26;
		for(int i=1;i<n;i++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!f[i][i+1][k])continue;
				if(s[i]==s[i+1])
				{
					//26 
					int K=k+1;
//					int rem=(ttnum+1)/2-n+K;
//					cerr<<n-K-K<<"!ss !\n";
					zy.a[n-K-K][tt-K]+=f[i][i+1][k];
//					cout<<rem<<" "<<f[i][i+1][k]<<" "<<K<<" "<<ans<<"!!\n";
//					ans-=ksm((n-K)*24+K,rem)*f[i][i+1][k];
//					ans-=ksm();
				}
			}
		}
		//cr 
//		ans.print();
//		zy.print();
		zy.cmod();
		run((ttnum+1)/2);
//		ans.print();
		res-=ans.a[1][tt];
		res%=mod,res+=mod,res%=mod;}
	}
	cout<<res<<"\n";
	/*  
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=n;k++)
		{
			if(!f[i+1][i][k])continue;// 
			cout<<f[i+1][i][k]<<"!!\n";
			int rem=(ttnum+1)/2-n+k;
			if(rem<0)continue;
			ans+=ksm((n-k)*24+k+26,rem)*f[i+1][i][k];
		}
	}
//	cout<<ans<<"ASD\n";
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<=n;k++)
		{
			if(!f[i][i][k])continue;// 
			int rem=(ttnum+1)/2-n+k;
//			cout<<rem<<"!!\n";
			if(rem<0)continue;//25 
			ans+=ksm((n-k)*24+k+26+1,rem)*f[i][i][k];
//			cout<<i<<" "<<i<<" "<<k<<" "<<f[i][i][k]<<"!!\n";
			ans%=mod;
		}
	}
//	cout<<ans<<"!!\n";
	// 
	if(ttnum&1)
	{
		for(int i=1;i<n;i++)
		{
			for(int k=0;k<=n;k++)
			{
				if(!f[i][i+1][k])continue;
				if(s[i]==s[i+1])
				{
					//26 
					int K=k+1;
					int rem=(ttnum+1)/2-n+K;
					cout<<rem<<" "<<f[i][i+1][k]<<" "<<K<<" "<<ans<<"!!\n";
					ans-=ksm((n-K)*24+K,rem)*f[i][i+1][k];
//					ans-=ksm();
				}
			}
		}
		ans%=mod,ans+=mod;
	}*/
//	cout<<ans%mod<<"\n";
	pc('1',1);
	return 0;
}