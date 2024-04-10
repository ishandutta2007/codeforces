#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 2005
int a[Maxn],at[Maxn];
int seq[Maxn],dfk=0;
bool b[Maxn];
int Ans[Maxn],cnt;
bool vis[Maxn];

inline int mex(){
	memset(vis,false,sizeof(bool)*(n+1));
	for(int i=1;i<=n;++i)vis[a[i]]=true;
	for(int i=0;i<=n;++i)
	    if(!vis[i])return i;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=false;
		for(int i=0;i<n;++i){
			int at=mex();
			if(at==n){
				for(int i=1;i<=n;++i)
				    if(!b[i]){
				    	a[i]=n;
				    	Ans[++cnt]=i;
				    	break;
					}
				at=mex();
			}
			Ans[++cnt]=at+1;
		    a[at+1]=at;b[at+1]=true;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i)printf("%d ",Ans[i]);
		puts("");
	}
	return 0;
}