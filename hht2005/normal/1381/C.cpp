#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define v first
#define x second
const int maxn=1e5+10;
int b[maxn],a[maxn],X[maxn],c[maxn],cnt;
vector<int>v[maxn];
priority_queue<pii>q;
int main() {
	int T,n,x,y;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&x,&y);
		int M=0,Max=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",b+i);
			a[i]=0;
			v[b[i]].push_back(i);
		}
		for(int i=1;i<=n+1;i++)
			if(v[i].empty())M=i;
			else q.push(make_pair(v[i].size(),i));
		for(int i=1;i<=x;i++) {
			pii t=q.top();
			q.pop();
			t.v--;
			a[*v[t.x].rbegin()]=t.x;
			v[t.x].pop_back();
			if(t.v)q.push(t);
		}
		cnt=0;
		for(int i=1;i<=n+1;i++) {
			Max=max(Max,int(v[i].size()));
			for(int j:v[i])X[cnt]=j,c[cnt++]=i;
		}
		for(int i=0;i<cnt;i++) {
			Max%=cnt;
			if(x>=y)break;
			if(c[i]!=c[Max]) {
				a[X[i]]=c[Max++];
				x++;
			}
		}
		for(int i=1;i<=n+1;i++)v[i].clear();
		while(!q.empty())q.pop();
		if(x<y) {
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++) {
			if(!a[i])a[i]=M;
			printf("%d ",a[i]);
		}
		puts("");
	}
	return 0;
}