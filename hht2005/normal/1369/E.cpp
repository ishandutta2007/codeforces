#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int w[maxn],x[maxn],y[maxn],s[maxn],q[maxn],f[maxn],h,e;
vector<int>p[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",x+i,y+i);
		s[x[i]]++,s[y[i]]++;
		p[x[i]].push_back(i);
		p[y[i]].push_back(i);
	}
	h=1,e=0;
	for(int i=1;i<=n;i++)
		if(s[i]<=w[i])
			for(int j:p[i])
				if(!f[j])f[q[++e]=j]=1;
	while(h<=e) {
		int v=q[h++];
		s[x[v]]--;
		s[y[v]]--;
		if(s[x[v]]<=w[x[v]])
			for(int j:p[x[v]])
				if(!f[j])f[q[++e]=j]=1;
		if(s[y[v]]<=w[y[v]])
			for(int j:p[y[v]])
				if(!f[j])f[q[++e]=j]=1;
	}
	if(e<m)puts("DEAD");
	else {
		puts("ALIVE");
		for(int i=m;i>=1;i--)
			printf("%d ",q[i]);
		puts("");
	}
	return 0;
}