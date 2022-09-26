#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
#define N 2333
const int inf=(1<<28)-1;
inline int read(){
	int x=0,f=1;
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
int n,qwq[N][N],qcnt,ans[N],IEE,tmp[N];
inline int Get(int x){
	return (1LL*rand()*rand()+rand())%x+1;
}
int Solve(vector<int> &myh){
	if((int)myh.size()==1)return myh[0];
	int y=(myh.size()==n&&n>20?IEE:Get(n));
	int mn=inf;
	vector<int> gu;
	for(auto x:myh){
		if(x==y){
			continue;
		}
		if(~qwq[x][y]){
			mn=min(mn,qwq[x][y]);
		}
		else{
			++qcnt;
			assert(qcnt<=4269);
			printf("? %d %d\n",x,y);
			fflush(stdout);
			qwq[x][y]=qwq[y][x]=read();
			mn=min(mn,qwq[x][y]);
		}
	}
	for(auto x:myh){
		if(x==y){
			gu.push_back(x);
			continue;
		}
		if(qwq[x][y]==mn){
			gu.push_back(x);
		}
	}
	ans[y]=mn;
	return Solve(gu);
}
int main(){
	memset(qwq,-1,sizeof(qwq));
	memset(ans,-1,sizeof(ans));
	srand(11111);
	n=read();
	vector<int> myh;
	for(int i=1;i<=n;++i){
		myh.push_back(i);
		tmp[i]=i;
	} 
	IEE=1;
	if(n>20){
		// n 1 
		random_shuffle(tmp+1,tmp+n+1);
		int mn=0x3f3f3f3f;
		for(int i=1;i<=10;++i){
			int u=tmp[i];
			int tot=0;
			for(int j=11;j<=20;++j){
				int v=tmp[j];
				printf("? %d %d\n",u,v);
				fflush(stdout);
				qwq[u][v]=qwq[v][u]=read();
				tot+=__builtin_popcount(qwq[u][v]);
			}
			if(tot<mn)mn=tot,IEE=u;
		}
	}
	int pos=Solve(myh);
	for(int i=1;i<=n;++i){
		if(i==pos){
			continue;
		}
		if(~qwq[pos][i])ans[i]=qwq[pos][i];
		if(!~ans[i]){
			++qcnt;
			assert(qcnt<=4269);
			printf("? %d %d\n",pos,i);
			fflush(stdout);
			ans[i]=read();
		}
	}
	printf("! ");
	for(int i=1;i<=n;++i){
		if(i==pos){
			printf("%d ",0);
			continue;
		}
		printf("%d ",ans[i]);
	}
	fflush(stdout);
	return 0;
}