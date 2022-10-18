#include <bits/stdc++.h>
#define maxn 1005
int n,d[maxn],u,v;
std::vector<int>ch[maxn];
void answer(int x){
	printf("! %d",x);
	fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
		d[u]++;d[v]++;
	}int cnt=n;
	while(1){
		if(cnt==1){
			for(int i=1;i<=n;++i)if(d[i]>=0)answer(i);
		}
		u=0;v=0;
		for(int i=1;i<=n;++i){
			 if(d[i]==1){
			 	if(!u)u=i;
			 	else v=i;
			 }
		}if(!v){
			answer(u);return 0;
		}
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int l;scanf("%d",&l);
		if(l==u)answer(u);
		if(l==v)answer(v);
		for(int i:ch[u])d[i]--;
		for(int i:ch[v])d[i]--;
		d[u]=d[v]=-1000000;
		cnt-=2;
	}return 0;
}