#include<bits/stdc++.h>
#define ll long long
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
const int xx=1e7+5;
int prim[xx/10],ct[xx/10],fi[xx],cnt;
bitset<xx>vs;
void pre(int n)
{
	fi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vs[i])prim[++cnt]=i,ct[cnt]++,fi[i]=i-1;
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>n)break;
			vs[i*prim[j]]=1,ct[j]++;
			if(i%prim[j]==0)fi[i*prim[j]]=fi[i]*prim[j];
			else fi[i*prim[j]]=fi[i]*fi[prim[j]];
			if(i%prim[j]==0)break;
		}
	}
}
int ans[]={0,0,0,0,1,1,8,8,13,21,44};
int n;
ll get(ll a){return a*(a-1)/2;}
ll S[xx];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main(){
//	pre(10000000);
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<prim[i]<<" "<<ct[i]<<"\n";
//	}
//	exit(0);
	n=read();
	pre(n);
	if(n<=10)cout<<ans[n]<<"\n",exit(0);
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=fi[i];
//	for(int i=1;i<=n;i++)cout<<i<<" "<<fi[i]<<"!!\n";
//	cout<<sum<<"!!\n";
	//i ii i 
	//1 1 
	sum=1ll*n*n-(sum*2-1);//gcd=1 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(gcd(i,j)!=1)
//			{
//				cout<<i<<" "<<j<<"\n";
//			}
//		}
//	}
//	cout<<sum<<"ASDD\n";
//	exit(0);
//	pre(n);
	ll ans=0;
	int tt=cnt;
	while(prim[tt]*2>n)tt--;
	int r=tt;
//	for(int i=1;i<=cnt;i++)ans+=get(ct[i]);
//	for(int i=1;i<=cnt;i++)cout<<i<<" "<<prim[i]<<"!!\n";
	for(int i=1;i<=cnt;i++)S[i]=S[i-1]+ct[i];
	for(int i=1;i<=tt;i++)
	{
		while(r>0&&1ll*prim[r]*prim[i]>n)r--;
		//i*i 
		//1~i-1 
		if(ct[i]!=1)
		{
			ans+=2ll*S[i]*ct[i];
			// 
			ans-=2ll*ct[i]*ct[i];
			ans+=1ll*ct[i]*(ct[i]+1);
			//2 
		}
		else 
		{
			//ri 
//			cout<<r<<" "<<i<<" "<<prim[4]<<"!!\n";
			assert(r<i);
			ans+=2ll*S[r];
			ans+=3ll*(S[i]-S[r]);
			ans-=1;//2 
		}
//		ans+=3*((i-1)-min(r,i-1));
	}
	//*2>n 
	for(int i=tt+1;i<=cnt;i++)ans+=2;//2 
//	cout<<ans<<"\n";
	//1 1 
//	cout<<sum/2<<"\n"; 
	//1 
	cout<<ans-n-((sum+(n-1))/2)+1<<"\n";
	pc('1',1);
	return 0;
}



/*table maker
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int f[55][55];
int main(){
	freopen("a.out","w",stdout);
//	n=read();
	cout<<"int ans[]={0,";
	for(int n=1;n<=10;n++)
	{
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(gcd(i,j)!=1)f[i][j]=f[j][i]=min(f[i][j],1);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		int re=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)if(f[i][j]<1e9)re+=f[i][j];
		cout<<re/2<<",";
	}
	cout<<"};";
	pc('1',1);
	return 0;
}
*/