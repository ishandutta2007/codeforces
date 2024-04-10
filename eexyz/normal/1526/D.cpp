#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define l(x) (x&(-x))
char to[1000],s[N],t[N],r[100];
int c[20],f[20],cc[N],cnt,n,fir[20],gg[N],C[20],pos[N];
long long ans;
void add(int x,int y){
	while(x<N)cc[x]+=y,x+=l(x);
}
int sum(int x){
	int ret=0;while(x)ret+=cc[x],x-=l(x);return ret;
}
void cal(){
	cnt=0;int i;ll ss=0;
	memset(fir,0,sizeof(fir));
	for(i=2;i<=4;++i){
		fir[f[i]]=fir[f[i-1]]+C[f[i-1]];
	}
	for(i=1;i<=n;++i)pos[i]=++fir[s[i]];
	for(i=1;i<=n;++i){
		add(pos[i],1);
		ss+=sum(N-1)-sum(pos[i]);
	}
	for(i=1;i<=n;++i)add(pos[i],-1);
	if(ss>=ans){
		for(i=1;i<=4;++i)gg[i]=f[i];
		ans=ss;
	}
}
void dfs(int now){
	if(now>4){cal();return ;}
	for(int i=1;i<=4;++i){
		if(!c[i])c[i]=1,f[now]=i,dfs(now+1),c[i]=0;
	}
}
int T,i;
int main(){
	cin>>T;
	to['A']=1;to['N']=2;to['T']=3;to['O']=4;
	r[1]='A';r[2]='N',r[3]='T';r[4]='O';
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		memset(C,0,sizeof(C));ans=0;
		for(i=1;i<=n;++i)s[i]=to[s[i]],++C[s[i]];
		dfs(1);
//		cout<<ans<<"\n";
		for(i=1;i<=4;++i){
			for(int j=1;j<=C[gg[i]];++j){
				cout<<r[gg[i]];
			}
		}
		cout<<"\n";
	}
}