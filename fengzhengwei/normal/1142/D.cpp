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
const int xx=1e5+5;
char s[xx];
int f[xx][11];
int sum[55];
int main(){
	for(int i=1;i<=10;i++)sum[i]+=sum[i-1],sum[i]+=i,sum[i]%=11;
	scanf("%s",s+1);
	int n=strlen(s+1);
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=10;j++)
		{
			f[i][j]=1;//mod 11 = 
			if(i!=n&&(s[i+1]-'0')<j)
			{
				//1~9 
				// 
				f[i][j]=1+f[i+1][(sum[j-1]+(s[i+1]-'0')+1+9)%11];
//				cout<<i<<" "<<j<<" "<<sum[j-1]+(s[i+1]-'0')+1+9<<" "<<sum[j]<<"\n";
			}
			// 
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
		}
		ans+=(s[i]!='0')*f[i][s[i]-'0'];
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}