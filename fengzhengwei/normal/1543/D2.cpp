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
int T;
int v[23];
int pw[23];
int main(){
	T=read();
	while(T--)
	{
		int n,m;
		n=read();
		m=read();
		if(m==2)
		{
			ll now=0;
			for(int i=0;i<n;i++)
			{
				cout<<(i^now)<<'\n';
				fflush(stdout);
				int r=read();
				if(r==1)break;
				now^=(i^now);
			}
			continue;
		}
		else 
		{
			memset(v,0,sizeof(v));
			int lim=0;
			pw[0]=1;
			for(int i=1;i<=20;i++)
			{
				pw[i]=pw[i-1]*m;
				if(pw[i]>n){
					lim=i;
					break;
				}
			}
			for(int i=0;i<n;i++)
			{
				int ans=0; 
//				cout<<v[0]<<" "<<v[1]<<"\n";
				for(int j=0;j<=lim;j++)
				{
					if(i&1)ans+=pw[j]*((v[j]+m-i/pw[j]%m)%m);
					else ans+=pw[j]*((v[j]+i/pw[j]%m)%m);
				}
				cout<<ans<<'\n';
				fflush(stdout);
				int r=read();
				if(r==1)break;
				for(int j=0;j<=lim;j++)
				{
					v[j]=(ans/pw[j]%m-v[j]+m)%m;
				}
			}
		}
	}
	return 0;
}