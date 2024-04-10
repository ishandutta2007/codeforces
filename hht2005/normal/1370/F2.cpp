#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],maxd,tot;
vector<int>pos[maxn];
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa,int d) {
	pos[d].push_back(x);
	maxd=max(maxd,d);
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa)dfs(to[i],x,d+1);
}
int main() {
	int T;
	string s;
	scanf("%d",&T);
	while(T--) {
		memset(hea,tot=0,sizeof(hea));
		int n,a,b,x,d;
		maxd=0;
		scanf("%d",&n);
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		printf("? %d",n);
		for(int i=1;i<=n;i++) {
			printf(" %d",i);
			pos[i].clear();
		}
		pos[0].clear();
		cout<<endl;
		cin>>x>>d;
		dfs(x,0,0);
		int l=(d-1)/2,r=min(d,maxd),D=d,X=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			printf("? %llu",pos[mid].size());
			for(int i:pos[mid])
				printf(" %d",i);
			cout<<endl;
			cin>>x>>d;
			if(d==D)l=mid+1,X=x;
			else r=mid-1;
		}
		pos[D].clear();
		dfs(X,0,0);
		printf("? %llu",pos[D].size());
		for(int i:pos[D])
			printf(" %d",i);
		cout<<endl;
		cin>>x>>d;
		cout<<"! "<<x<<' '<<X<<endl;
		cin>>s;
		if(s=="Incorrect")break;
	}
	return 0;
}