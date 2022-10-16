#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=405;
char s[xx],c[xx];
int f[xx];
int main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",c+1);
		int n=strlen(s+1),m=strlen(c+1);
		int now=0;
		vector<int>chose;
		int vs=0;
		for(int i=1;i<=m;i++)
		{
			memset(f,-0x3f,sizeof(f));
			f[0]=i;
			for(int j=1;j<=n;j++)
			{
				for(int w=i;w>=0;w--)
				{
					if(f[w]<0)continue;
					if(w!=i&&c[w+1]==s[j])f[w+1]=max(f[w+1],f[w]);
					if(f[w]!=m&&c[f[w]+1]==s[j])f[w]++;
				}
			}
			if(f[i]==m)
			{
				puts("YES");
				vs=1;
				break;
			}
		}
		if(!vs)puts("NO");
	}
	return 0;
}