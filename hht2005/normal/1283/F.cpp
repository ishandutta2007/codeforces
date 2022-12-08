#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define v first
#define x second
const int maxn=2e5+10;
int fa[maxn],deg[maxn],son[maxn],val[maxn],n;
priority_queue<pii,vector<pii>,greater<pii> >q;
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d",fa+i);
		deg[fa[i]]++;
	}
	for(int i=1;i<=n;i++) {
		val[i]=i;
		if(!deg[i])q.push(mp(i,i));
	}
	for(int i=n-1;i>=1;i--) {
		pii t=q.top();
		q.pop();
		val[fa[i]]=max(val[fa[i]],t.v);
		son[i]=t.x;
		if(!--deg[fa[i]])q.push(mp(val[fa[i]],fa[i]));
	}
	printf("%d\n",fa[1]);
	for(int i=1;i<n;i++)
		printf("%d %d\n",fa[i],son[i]);
	return 0;
}