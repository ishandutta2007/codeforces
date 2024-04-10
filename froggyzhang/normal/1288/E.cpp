#include<iostream>
#include<cstdio>
#include<cstring>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],m,w[N],vis[N],mx[N];
ordered_set<int> s;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		w[i]=i;
		s.insert(i);
	}
	for(int i=1;i<=m;++i){
		int x=read();
		mx[x]=max(mx[x],(int)s.order_of_key(w[x])+1);
		vis[x]=1;
		s.erase(w[x]);
		w[x]=-i;
		s.insert(w[x]);
	}
	for(int i=1;i<=n;++i){
		mx[i]=max(mx[i],(int)s.order_of_key(w[i])+1);
	}
	for(int i=1;i<=n;++i){
		printf("%d %d\n",vis[i]?1:i,mx[i]);
	}
	return 0;
}