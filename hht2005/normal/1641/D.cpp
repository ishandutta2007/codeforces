#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,base=6100001;
int a[N][7],w[N],p[N],n,m;
using VI=vector<int>;
using ull=unsigned long long;
unordered_map<ull,int>S;
int cmp(int a,int b) {
	return w[a]<w[b];
}
int qry(int x) {
	int sum=0;
	for(int i=1;i<1<<m;i++) {
		int cnt=0;
		ull V=0;
		for(int j=0;j<m;j++)
			if(i>>j&1) {
				cnt++;
				V=V*base+a[x][j+1];
			}
		if(cnt&1)sum+=S[V];
		else sum-=S[V];
	}
	return sum;
}
void add(int x,int v) {
	for(int i=0;i<1<<m;i++) {
		ull V=0;
		for(int j=0;j<m;j++)
			if(i>>j&1)V=V*base+a[x][j+1];
		S[V]+=v;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			scanf("%d",a[i]+j);
		sort(a[i]+1,a[i]+m+1);
		scanf("%d",w+i);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	int L=0,R=0;
	for(int i=1;i<=n;i++) {
		if(qry(p[i])!=i-1) {
			R=i,L=i-1;
			add(p[i-1],-1);
			while(qry(p[i])!=L-1) {
				L--;
				add(p[L],-1);
			}
			break;
		}
		add(p[i],1);
	}
	if(!L)puts("-1"),exit(0);
	int ans=w[p[L]]+w[p[R]];
	for(int i=R+1;i<=n;i++) {
		int FL=0;
		while(L>1&&qry(p[i])!=L-1) {
			L--;
			FL=1;
			add(p[L],-1);
		}
		if(FL)ans=min(ans,w[p[L]]+w[p[i]]);
	}
	cout<<ans<<endl;
	return 0;
}