#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0');if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
char s[xx],t[xx];
int to[xx][26];
int main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n=strlen(s+1);
		for(int i=0;i<26;i++)to[n][i]=0;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)to[i][j]=to[i+1][j];
			to[i][s[i+1]-'a']=i+1;
		}
		int o=strlen(t+1);
		int now=0,ans=1;
		for(int i=1;i<=o;i++)
		{
			if(!to[0][t[i]-'a']){ans=-1;break;}
			if(!to[now][t[i]-'a'])ans++,now=0;
			now=to[now][t[i]-'a'];
		}
		cout<<ans<<"\n";
	}
	return 0;
}