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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
int n,m;
ll f[xx][8];
/*
0:i i-1={i-2,i-1} 
1:i i={i-1,i} //fii>=i-1 
2:i i+1={i-1,i} 
*/
char s[xx];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	f[0][7]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(!f[i][j])continue;
//				cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
				int to=0;
				to+=1*((j>>1&1)||((j>>0&1)&&(k==s[i]-'a')));
				if(!(to&1)&&!(j>>2&1)&&k!=s[i+1]-'a')continue;
				to+=2*((j>>1&1)&&(k==s[i+1]-'a'));
				to+=4*((to>>1&1)||((j>>2&1)&&(k==s[i+2]-'a')));
				f[i+1][to]+=f[i][j];
			}
		}
	}
	cout<<f[n][0]+f[n][1]<<"\n";
	pc('1',1);
	return 0;
}