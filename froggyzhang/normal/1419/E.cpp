#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 23333
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,t[N],k,vis[N];
vector<pair<int,int> > fac;
void Solve(){
	k=0,fac.clear();
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			t[++k]=i;
			if(i*i!=n)t[++k]=n/i;
		}
	}
	t[++k]=n;
	for(int i=1;i<=k;++i){
		vis[i]=0;
	}
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			int cnt=0;
			while(n%i==0)n/=i,++cnt;
			fac.emplace_back(i,cnt);
		}
	}
	if(n>1){
		fac.emplace_back(n,1);
	}
	if((int)fac.size()==1){
		for(int i=1,num=1;i<=fac[0].second;++i){
			num*=fac[0].first;
			printf("%d ",num);
		}
		printf("\n");
		puts("0");
		return;
	}
	if((int)fac.size()==2&&fac[0].second==1&&fac[1].second==1){
		printf("%d %d %d\n",fac[0].first,fac[1].first,fac[0].first*fac[1].first);
		puts("1");
		return;
	}
	for(int i=0;i<(int)fac.size();++i){
		int u=fac[i].first,v=fac[(i+1)%fac.size()].first;
		for(int j=1;j<=k;++j){
			if(vis[j])continue;
			if(i==0&&t[j]==u*fac.back().first)continue;
			if(t[j]%u==0){
				if(t[j]^(u*v))printf("%d ",t[j]);
				vis[j]=1;
			}
		}
		if(fac.size()!=2||i!=0)printf("%d ",u*v);
	}
	printf("\n");
	puts("0");
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}