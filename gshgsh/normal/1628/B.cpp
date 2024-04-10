#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N;string s[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)cin>>s[i];bool flag=0;
		For(i,1,N)if(s[i].size()==1){flag=1;break;}
		For(i,1,N)if(s[i].size()==2&&s[i][0]==s[i][1]){flag=1;break;}
		For(i,1,N)if(s[i].size()==3&&s[i][0]==s[i][2]){flag=1;break;}
		if(flag){cout<<"YES\n";continue;}
		map<string,bool>vis;For(i,1,N)if(s[i].size()==2){string t=s[i];swap(t[0],t[1]);if(vis[t]){flag=1;break;}vis[s[i]]=1;}
		if(flag){cout<<"YES\n";continue;}
		vis.clear();For(i,1,N)if(s[i].size()==2)vis[s[i]]=1;else{string t;t+=s[i][2];t+=s[i][1];if(vis[t]){flag=1;break;}}
		if(flag){cout<<"YES\n";continue;}
		vis.clear();For(i,1,N)if(s[i].size()==3){string t;t+=s[i][0];t+=s[i][1];vis[t]=1;}else{string t=s[i];swap(t[0],t[1]);if(vis[t]){flag=1;break;}}
		if(flag){cout<<"YES\n";continue;}
		vis.clear();For(i,1,N)if(s[i].size()==3){string t=s[i];swap(t[0],t[2]);if(vis[t]){flag=1;break;}vis[s[i]]=1;}
		cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}