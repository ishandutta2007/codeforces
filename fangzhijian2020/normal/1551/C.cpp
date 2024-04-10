#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}

int T,n,m,Ts;char c[200005];
struct node{
	int a[26];
	bool operator<(const node&b)const{
		return a[Ts]>b.a[Ts];
	}
}s[200005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i){
			scanf("%s",c+1);m=strlen(c+1);
			for(int j=0;j<26;++j)s[i].a[j]=-m;
			for(int j=1;j<=m;++j)s[i].a[c[j]-'a']+=2;
		}
		int ans=0;
		for(Ts=0;Ts<26;++Ts){
			int sum=0;
			sort(s+1,s+n+1);
			for(int i=1;i<=n;++i){
				sum+=s[i].a[Ts];
				if(sum<=0)break;
				ans=max(ans,i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}