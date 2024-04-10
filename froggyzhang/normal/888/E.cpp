#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define N 55
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
int n,m,mid;
int a[N],ans;
set<int> s;
void dfs1(int u){
	if(u>mid)return;
	vector<int> num;
	for(auto t:s){
		num.push_back((a[u]+t)%m);
	}
	for(auto x:num){
		s.insert(x);
	}
	dfs1(u+1);
}
void dfs2(int u,int d){
	if(u==mid){
		ans=max(ans,d+*--s.lower_bound(m-d));
		return;
	}
	dfs2(u-1,d),dfs2(u-1,(d+a[u])%m);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read()%m;
	}
	mid=((n+1)>>1);
	s.insert(0);
	dfs1(1); 
	dfs2(n,0);
	printf("%d\n",ans);
	return 0;
}