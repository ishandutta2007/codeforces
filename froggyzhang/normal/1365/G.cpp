#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
#define N 1234
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,vis[N<<3],st[N],p[N];
ll ans[15];
inline int check(){
	int qwq=0;
	for(int i=1;i<=13;++i){
		if(p[i])qwq|=(1<<(i-1));
	}
	return qwq;
}
int main(){
	srand(time(0));
	n=read();
	for(int i=1;i<=13;++i){
		p[i]=(i<=6?1:0);
	}
	for(int i=1;i<=n;++i){
		int myh=0;
		while(vis[myh=check()]){
			random_shuffle(p+1,p+13+1);
		}
		st[i]=myh;
		vis[myh]=1;
	}
	for(int k=1;k<=13;++k){
		vector<int> wzp;
		for(int i=1;i<=n;++i){
			if((st[i]>>(k-1))&1){
				wzp.push_back(i);
			}
		}
		if(wzp.empty())continue;
		printf("? %d ",(int)wzp.size());
		for(auto x:wzp){
			printf("%d ",x);
		}
		printf("\n");
		fflush(stdout);
		ans[k]=read();
	}
	printf("! ");
	for(int i=1;i<=n;++i){
		ll zyy=0;
		for(int k=1;k<=13;++k){
			if(!((st[i]>>(k-1))&1)){
				zyy|=ans[k];
			}
		}
		printf("%I64d ",zyy);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}