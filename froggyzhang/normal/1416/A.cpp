#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 300030
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
vector<int> pos[N];
int ans[N],n,a[N],T;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		pos[i].clear();
		ans[i]=n+1;
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		if(pos[i].empty())continue;
		int las=0,mx=0;
		for(auto x:pos[i]){
			mx=max(mx,x-las-1);
			las=x;
		}
		mx=max(n-las,mx);
		++mx;
		ans[mx]=min(ans[mx],i);
	} 
	ans[0]=n+1;
	for(int i=1;i<=n;++i){
		ans[i]=min(ans[i],ans[i-1]);
		printf("%d ",ans[i]>n?-1:ans[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}