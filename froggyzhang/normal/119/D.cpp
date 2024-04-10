#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
char s[N],t[N];
int n;
void Z(char *s,int n,int *z){
	z[1]=n;
	for(int i=2,l=0,r=1;i<=n;++i){
		z[i]=i<=r?min(r-i+1,z[i-l+1]):0;
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
void exkmp(char *s,char *t,int n,int m,int *p){
	static int z[N];
	Z(t,m,z);
	for(int i=1,l=0,r=0;i<=n;++i){
		p[i]=i<=r?min(r-i+1,z[i-l+1]):0;
		while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1])++p[i];
		if(i+p[i]-1>r)l=i,r=i+p[i]-1;
	}
}
int a[N],b[N];
int g[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.getline(s+1,N);
	cin.getline(t+1,N);
	if((n=strlen(s+1))!=strlen(t+1)){
		cout<<-1<<' '<<-1<<'\n';
		return 0;
	}
	exkmp(s,t,n,n,a);
	reverse(s+1,s+n+1);
	exkmp(t,s,n,n,b);
	reverse(s+1,s+n+1);
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;++i){
		g[i+b[i]]=min(g[i+b[i]],i);
	}
	for(int i=n;i>=1;--i){
		g[i]=min(g[i],g[i+1]);
	}
	pair<int,int> ans=make_pair(-1,1);
	for(int i=0;i<n;++i){
		if(i>0&&s[i]!=t[n-i+1])break;
		int o=g[n-i+1];
		if(a[i+1]>=o-1){
			ans=max(ans,make_pair(i-1,-(i+o-1)));
		}
	}
	cout<<ans.first<<' '<<-ans.second<<'\n';
	return 0;
}