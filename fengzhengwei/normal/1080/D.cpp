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
int T;
ll ans;
__int128 rem;
ll nm[55],k;
/// 
__int128 mul(__int128 a,__int128 b){return a*b;}
void get(ll n,ll bc)
{
	if(bc==0)return;
	bc--,k-=n;
	if(k<0)return ;
	rem+=mul(n*4-(n*2+1),nm[bc]);
//	cout<<(ll)rem<<"!\n";
	if(rem>=k)return ans=bc,void();
	return get((n*2+1),bc);
}
int main(){
	nm[0]=0;
	for(int i=1;i<=31;i++)
		nm[i]=nm[i-1]*4+1;
	T=read();
	while(T--)
	{
		ll n=read();
		k=read();
		ans=-1,rem=0;
		if(n>31)
		{
			puts("YES");
			cout<<n-1<<"\n";
			continue;
		}
		get(1,n);
		if(ans==-1)
		{
			puts("NO");
			continue;
		}
//		puts("YES");
		cout<<"YES "<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}