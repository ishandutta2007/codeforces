#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
set<int>s[maxn];
int fa[maxn],cnt;
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int a,int b) {
	a=get(a),b=get(b);
	if(s[a].size()>s[b].size())swap(a,b);
	fa[a]=b;
	for(int i:s[a]) {
		if(!i)continue;
		set<int>::iterator it=s[b].lower_bound(i);
		if(it!=s[b].end()&&*it==i+1)cnt--;
		if(--it!=s[b].begin()&&*it==i-1)cnt--;
	}
	for(int i:s[a]) {
		if(!i)continue;
		s[b].insert(i);
	}
}
int main() {
	int n,m,p,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		s[i].insert(0);
	for(int i=1;i<=n;i++) {
		scanf("%d",&p);
		if(*s[p].rbegin()!=i-1)cnt++;
		s[p].insert(fa[i]=i);
	}
	printf("%d\n",cnt);
	for(int i=1;i<m;i++) {
		scanf("%d%d",&a,&b);
		merge(a,b);
		printf("%d\n",cnt);
	}
	return 0;
}