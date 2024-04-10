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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
const int mod=998244353;
//int a[xx];
char s[xx];
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
//int n,m,q,k,tt;
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		ll a=read(),b=read(),c=read();
		scanf("%s",s+1);
		if(n==1)
		{
			puts("0");
			continue;
		}
		int cr0=0,cr1=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')cr0=1;
			if(s[i]=='1')cr1=1;
		}
		if(!cr0)//1 
		{
			cout<<b<<"\n";
			continue;
		}
		if(!cr1)//0 
		{
			cout<<a<<"\n";
			continue;
		}
		//
		int n1=0,n0=0,n2=0;//n23(1) 
		// 
		int L=0,R=0;
		while(s[L+1]=='0')L++;
		while(s[n-R]=='0')R++;
		multiset<int>S;
		for(int i=L+1;i<=n-R;i++)
		{
			if(s[i]=='1')continue;
			int j=i;
			while(s[j+1]=='0')j++;
			S.insert(j-i+1);
			i=j;
		}
		for(int i=1;i<n;i++)if(s[i]==s[i+1]&&s[i]=='1')n1++;else if(s[i]==s[i+1]&&s[i]=='0')n0++;
		if(c>=b)//3 
		{
			if(n1==n0)
			{
				cout<<1ll*n1*(a+b)<<"\n";
			}
			else if(n1>n0)
			{
				cout<<1ll*n0*(a+b)+b<<"\n";
				
			}
			else if(n0>n1)
			{
				cout<<1ll*n1*(a+b)+a<<"\n";
			}
			continue;
		}
		//32 
		//2 
		//13 
		ll ans=0;
		if(n1)ans=max(ans,b);
		if(n0)ans=max(ans,a);
		if(n1)
		{
			ll res=0;
			while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
			n1--,res+=b;
			while(n1||n2||L||R)// 1 
			{
				if(!n1)
				{
					while(n2)n2--,res-=c,res+=b;
					break;
				}
				
				if(n0)
				{
					n0--,n1--,res+=a+b;
					if(S.size())
					{
						int o=*S.begin();
						S.erase(S.begin());
						o--;
						S.insert(o);
						while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
					}
					else if(L>1)L--;
					else R--;
					//LR ()
					
				}
				else 
				{
					if(n2)n2--,res-=c,res+=b;//n1 
					else 
					{
						if(S.size())
						{
							int o=*S.begin();
							S.erase(S.begin());
							o--;
							S.insert(o);
							while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
							n1--,res-=c,res+=b;
						}
						else if(L)L--,n1--,res-=c,res+=b;
						else if(R)R--,n1--,res-=c,res+=b;
						else break;// 
					}
				}
			}
			ans=max(ans,res);
		}
		
		
		
		
		// 
		//11 
		n1=0,n0=0,n2=0;//n23 
		// 
		L=0,R=0;
		while(s[L+1]=='0')L++;
		while(s[n-R]=='0')R++;
		S.clear();
		for(int i=L+1;i<=n-R;i++)
		{
			if(s[i]=='1')continue;
			int j=i;
			while(s[j+1]=='0')j++;
			S.insert(j-i+1);
			i=j;
		}
		for(int i=1;i<n;i++)if(s[i]==s[i+1]&&s[i]=='1')n1++;else if(s[i]==s[i+1]&&s[i]=='0')n0++;
		// 
		
		
		//12122121211 
//		if(n0)
//		{
			ll res=0;
			while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
//			n0--,res+=a;
			while(n1||n2||L||R)// 
			{
				if(!n1)
				{
					while(n2)n2--,res-=c,res+=b;
					break;
				}
				
				if(n0)
				{
					n0--,n1--,res+=a+b;
					if(S.size())
					{
						int o=*S.begin();
						S.erase(S.begin());
						o--;
						S.insert(o);
						while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
					}
					else if(L>1)L--;
					else R--;
					//LR ()
					
				}
				else 
				{
					if(n2)n2--,res-=c,res+=b;//n1 
					else 
					{
						if(S.size())
						{
							int o=*S.begin();
							S.erase(S.begin());
							o--;
							S.insert(o);
							while(S.size()&&*S.begin()==1)S.erase(S.begin()),n2++;
							n1--,res-=c,res+=b;
						}
						else if(L)L--,n1--,res-=c,res+=b;
						else if(R)R--,n1--,res-=c,res+=b;
						else break;// 
					}
				}
			}
			if(n0)res+=a;
			ans=max(ans,res);
//		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}