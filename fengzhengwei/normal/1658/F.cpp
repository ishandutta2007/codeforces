#include<bits/stdc++.h>
#define ll long long
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
	wt(x);pc(op,0);
}
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
	ll ksm(ll a,ll b)
	{
		ll ans=1;
		while(b)
		{
			if(b&1)ans*=a,ans%=mod;
			a*=a,a%=mod,b>>=1;
		}
		return ans;
	}
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,k,q,a[xx];
char s[xx];
int sum[xx];
int main(){
//	freopen("a.in","r",stdin);
	
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		scanf("%s",s+1);
//		if(n%m!=0)
//		{
//			cerr<<"1 !";
//			exit(0);
//		}
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(s[i]-'0');
		int op=-1;
		if(1.0*sum[n]*m/n!=1ll*sum[n]*m/n)
		{
			puts("-1");
			continue;
//			op=2;
//			break;
		}
		int re=1ll*sum[n]*m/n;
		for(int i=m;i<=n;i++)
		{
			if(sum[i]-sum[i-m]==re)
			{
				cout<<1<<"\n"<<i-m+1<<" "<<i<<"\n";
				op=3;
				break;
			}
		}
		if(op==3)continue;
		for(int i=n+1;i<=n+n;i++)
			sum[i]=sum[i-1]+(s[i-n]-'0');
		for(int i=n+1;i<=n+n;i++)
		{
			if(sum[i]-sum[i-m]==re)
			{
				cout<<2<<"\n";
				cout<<1<<" "<<i-n<<"\n";
				cout<<i-m+1<<" "<<n<<"\n";
//				cout<<1<<"\n"<<i-m+1<<" "<<i<<"\n";
				op=3;
				break;
			}
		}
		continue;
		exit(0);
		// 
		vector<int>id;
		id.push_back(0);
		for(int i=1;i<=n;i++)if(s[i]=='1')id.push_back(i);
		id.push_back(n+1);
		multiset<int>S;
		int RE=0,st,ed,num;
		for(int i=1;i<1+re-1;i++)S.insert(id[i+1]-id[i]);
		for(int i=1;i<id.size()-1;i++)
		{
			int to=i+re-1;
			if(to>=id.size()-1)break;
			if(id[to]-id[i]+1>=m&&id[to]-id[i]+1-*--S.end()<=m)
			{
				RE=1,st=i,ed=to,num=*--S.end();
				break;
			}
			S.erase(S.find(id[i+1]-id[i]));
		}
		if(RE)
		{
			int l1,r1,l2,r2;
//			int l1=id[L1],r1=id[R1],l2=id[L2],r2=id[R2];
			for(int i=st;i<=ed;i++)
			{
				if(id[i+1]-id[i]==num)
				{
					l1=id[st],r1=id[i];
					l2=id[i+1],r2=id[ed];
					break;
				}
			}
			int A=m;
			A-=r1-l1+1,A-=r2-l2+1;
			while(A&&s[l1-1]=='0')l1--,A--;
			while(A&&s[r1+1]=='0')r1++,A--;
			while(A&&s[r2+1]=='0')r2++,A--;
			while(A&&s[l2-1]=='0')l2--,A--;
			cout<<l1<<" "<<r1<<"\n";
			cout<<l2<<" "<<r2<<"\n";
			assert(l1>=1&&l2>=1&&r1<=n&&r2<=n);
			assert(sum[r1]-sum[l1-1]+sum[r2]-sum[l2-1]==re&&r1-l1+1+r2-l2+1==m);
			continue;
		}
//		for(auto it:id)cout<<it<<" ";
//		puts("");
		int lmx=0,rmx=0,mxlen=0;
		for(int i=re;i<id.size()-1;i++)
		{
			//i-re+1~i
			if(mxlen<id[i+1]-id[i-re]-1)
			{
				mxlen=id[i+1]-id[i-re]-1;
				lmx=i-re+1,rmx=i;
//				cout<<i<<" "<<id.size()<<" "<<i-re<<" "<<id[lmx]<<" "<<id[rmx]<<"ASD\n";
			}
		}
		int lmn=0,rmn=0,mnlen=1e9;
		for(int i=re;i<id.size()-1;i++)
		{
			//i-re+1~i
			if(mnlen>id[i]-id[i-re+1]+1)
			{
				mnlen=id[i]-id[i-re+1]+1;
				lmn=i-re+1,rmn=i;
			}
		}
//		cout<<lmn<<" "<<lmx<<" "<<rmn<<" "<<rmx<<"ASD  "<<id[lmn]<<" qq "<<id[lmx]<<" "<<id[rmn]<<" "<<id[rmx]<<" "<<mnlen<<" "<<mxlen<<"!!\n";
		cout<<2<<"\n"; 
		// 
		int cr=0;
		#define len (id[R1]-id[L1]+1+id[R2]-id[L2]+1)
		#define pr(x) (id[x]-id[x-1])
		#define nx(x) (id[x+1]-id[x])
		int L1,R1,L2,R2;
		if(rmn>=rmx)
		{
			L1=lmx,R1=lmx,L2=lmn+1,R2=rmn;// 
			while(L2<=R2)
			{
				if(len+pr(L1)+nx(R1)+pr(L2)+nx(R2)>=m)
				{
					cr=1;
					break;
				}
				L2++,R1++;
			}
		}
		else 
		{
			L1=lmn,R1=rmn-1,L2=rmx,R2=rmx;// 
			while(L1<=R1)
			{
				if(len+pr(L1)+nx(R1)+pr(L2)+nx(R2)>=m)
				{
					cr=1;
					break;
				}
				R1--,L2--;
//				L2++,R1++;
			}
		}
		if(!cr)assert(0);
		int A=m;
		A-=len;
		int l1=id[L1],r1=id[R1],l2=id[L2],r2=id[R2];
//		cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<len<<"!!!\n";
		while(A&&s[l1-1]=='0')l1--,A--;
		while(A&&s[r1+1]=='0')r1++,A--;
		while(A&&s[r2+1]=='0')r2++,A--;
		while(A&&s[l2-1]=='0')l2--,A--;
		cout<<l1<<" "<<r1<<"\n";
		cout<<l2<<" "<<r2<<"\n";
		assert(l1>=1&&l2>=1&&r1<=n&&r2<=n);
		assert(sum[r1]-sum[l1-1]+sum[r2]-sum[l2-1]==re&&r1-l1+1+r2-l2+1==m);
	}
	exit(0);
	T=read();
	while(T--)
	{
		n=read(),m=read();
		scanf("%s",s+1);
//		if(n%m!=0)
//		{
//			cerr<<"1 !";
//			exit(0);
//		}
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(s[i]-'0');
		int op=-1;
		if(1.0*sum[n]/n*m!=1ll*sum[n]*m/n)
		{
			op=2;
//			break;
		}
		int re=1ll*sum[n]*m/n;
		for(int i=m;i<=n;i++)
		{
			if(sum[i]-sum[i-m]==re)
			{
				op=3;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(i+j-1>n)break;
				for(int k=i+j;k<=n;k++)
				{
					if(k+(m-j)-1>n)break;
//				if(i==6&&j==1)cout<<k<<"ASD\n";
					if(sum[i+j-1]+sum[k+(m-j)-1]-sum[i-1]-sum[k-1]==re)
					{
						op=4;
						break;
//						cerr<<"4 !";
//						exit(0);
					}
				}
			}
		}
//		cerr<<op<<"DFGASD!!\n";
		if(op==-1)
		{
			cerr<<n<<" "<<m<<"!\n";
			for(int i=1;i<=n;i++)cerr<<s[i];
			assert(0);
		}
		else 
		{
		cout<<op<<" !\n";
			
		}
	}
//	assert(0);
	pc('1',1);
	return 0;
}