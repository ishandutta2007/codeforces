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
const int mod=1e9+7;
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
const int xx=1e4+5;//22 
char s[xx],c[3][xx],ans[xx];
int to[xx];
bitset<xx>bit[3][22];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	cout<<"? ";
	for(int i=0;i<n;i++)cout<<char((i/484)+'a');
	puts("");
	fflush(stdout);
	scanf("%s",c[0]);
	cout<<"? ";
	for(int i=0;i<n;i++)cout<<char((i/22)%22+'a');
	puts("");
	fflush(stdout);
	scanf("%s",c[1]);
	cout<<"? ";
	for(int i=0;i<n;i++)cout<<char(i%22+'a');
	puts("");
	fflush(stdout);
	scanf("%s",c[2]);
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)bit[i][c[i][j]-'a'][j]=1;
	for(int i=0;i<n;i++)
		to[i]=(bit[0][(i/484)]&bit[1][(i/22)%22]&bit[2][i%22])._Find_first(),ans[i]=s[to[i]];
	cout<<"! "<<ans<<"\n";
	pc('1',1);
	return 0;
}