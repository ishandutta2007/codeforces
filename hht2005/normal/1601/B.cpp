#include<bits/stdc++.h>
using namespace std;
const int N=15e5+10;
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
vector<pii>S[N];
int a[N],b[N],dis[N],f[N],pre[N],Now[N],n;
deque<int>q;
void build(int p,int l,int r) {
	if(l==r) {
		Now[p+n]=l;
		S[p+n].pb(mp(l+b[l],1));
		return;
	}
	S[p+n].pb(mp(p*2+n,0));
	S[p+n].pb(mp(p*2+n+1,0));
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void add(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		S[y].pb(mp(p+n,0));
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y);
	if(y>mid)add(p<<1|1,mid+1,r,x,y);
}
void print(int x) {
	if(x==n)return;
	print(pre[x]);
	if(Now[x])printf("%d ",Now[x]);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		add(1,1,n,i-a[i],i);
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	q.push_back(n);
	while(!q.empty()) {
		int x=q.front();
		q.pop_front();
		if(f[x])continue;
		f[x]=1;
		for(pii s:S[x])
			if(dis[s.first]>dis[x]+s.second) {
				dis[s.first]=dis[x]+s.second;
				pre[s.first]=x;
				if(s.second)q.push_back(s.first);
				else q.push_front(s.first);
			}
	}
	int ans=1e9,I=0;
	for(int i=1;i<=n;i++)
		if(i==a[i]&&ans>dis[i]+1)ans=dis[I=i]+1;
	if(ans>1e8)puts("-1");
	else {
		printf("%d\n",ans);
		print(I);
		puts("0");
	}
	return 0;
}