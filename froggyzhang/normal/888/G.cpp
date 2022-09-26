#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,a[N],root; 
int trie[N<<5][2],L[N<<5],R[N<<5],tot;
void Insert(int x,int pos){
	int u=root;
	for(int i=30;i>=0;i--){
		int c=((x>>i)&1);
		if(!trie[u][c])trie[u][c]=++tot;
		u=trie[u][c];
		L[u]=min(L[u],pos),R[u]=max(R[u],pos);
	}
}
int Query(int x,int u,int dep){
	int ans=0;
	for(int i=dep;i>=0;--i){
		int c=((x>>i)&1);
		if(trie[u][c])u=trie[u][c];
		else u=trie[u][c^1],ans+=(1<<i);
	}
	return ans;
}
ll dfs(int u,int dep){
	if(trie[u][0]&&trie[u][1]){
		int mn=inf;
		for(int i=L[trie[u][0]];i<=R[trie[u][0]];++i){
			mn=min(mn,Query(a[i],trie[u][1],dep-1));
		}
		return dfs(trie[u][0],dep-1)+dfs(trie[u][1],dep-1)+mn+(1<<dep);
	}
	if(trie[u][0])return dfs(trie[u][0],dep-1);
	if(trie[u][1])return dfs(trie[u][1],dep-1);
	return 0;
}
int main(){
	root=tot=1;
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	memset(L,0x3f,sizeof(L));
	L[root]=1,R[root]=n;
	for(int i=1;i<=n;++i){
		Insert(a[i],i);
	}
	printf("%lld\n",dfs(root,30));
	return 0;
}