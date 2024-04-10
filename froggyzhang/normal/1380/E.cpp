#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
#define N 200020
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
int n,m,ans;
set<int> s[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int x=read();
		s[x].insert(i);
	}
	ans=n-1;
	for(int i=1;i<=m;++i){
		int las=-1;
		for(auto x:s[i]){
			if(x==las+1)--ans;
			las=x;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<m;++i){
		int u=read(),v=read();
		if(s[u].size()<s[v].size())swap(s[u],s[v]);
		for(auto x:s[v]){
			auto it=s[u].lower_bound(x);
			if(it!=s[u].end()&&(*it)==x+1)--ans;
			if(it!=s[u].begin()&&(*--it)==x-1)--ans;
		}
		for(auto x:s[v]){
			s[u].insert(x);
		}
		printf("%d\n",ans);
	}
	return 0;
}