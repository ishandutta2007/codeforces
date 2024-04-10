#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline void chkmin(int &x,int y) {
	if(y<x) x=y;
}
inline void chkmax(int &x,int y) {
	if(y>x) x=y;
}
const int N=1e6+5;
int n,m;
int p[N],a[N],b[N];
struct node {
	int id;
	bool operator < (const node &b) const {
		return p[id]<p[b.id];
	}
};
set<node> s[4];
int main(){
	n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) a[i]=read(),s[a[i]].insert({i});
	for(int i=1;i<=n;i++) b[i]=read(),s[b[i]].insert({i});
	m=read();
	while(m--){
		int c=read();
		if(s[c].empty()) {printf("-1 ");}
		else {
			int u=(*s[c].begin()).id;
			s[a[u]].erase({u});
			s[b[u]].erase({u});
			printf("%d ",p[u]);
		}
	}
	return 0;
}