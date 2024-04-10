#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef long long ll;

const int N=1e5+50;
int a[N];
int m,n;
bool check(int l,int r) {
	int mn=a[1],mx=a[1];
	FOR(i,1,n) {
		int p=1e9+1,q=0;
		if(r<mn) return 0;
		p=max(l-mx,0);
		q=r-mn;
		
		if(p>a[i+1]-a[i]) return 0;
		q=min(q,a[i+1]-a[i]);
		mn=a[i+1]-a[i]-q;
		mx=a[i+1]-a[i]-p;
	}
	return mn==0;
}
int f[N],g[N];
int ans[N];
void print(int l,int r) {
	int mn=a[1],mx=a[1];
	FOR(i,1,n) {
		f[i]=mn,g[i]=mx;
		
		int p=1e9+1,q=0;
		p=max(l-mx,0);
		q=r-mn;
		
		q=min(q,a[i+1]-a[i]);
		mn=a[i+1]-a[i]-q;
		mx=a[i+1]-a[i]-p;
	}
	int v=0;
	DOR(i,n,1) {
		ans[i]=a[i+1]-v;
		
		v=a[i+1]-a[i]-v;
		v=max(f[i],l-v);
	}
	FOR(i,1,n) printf("%d %d\n",ans[i-1],ans[i]);
}
int main() {
	scanf("%d%d",&m,&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	a[n+1]=m;
	int l=0,r=m;
	int L=l,R=r;
	while(L<=R) {
		int mid=L+R>>1;
		if(check(l,mid)) r=mid,R=mid-1;
		else L=mid+1;
	}
	L=l,R=r;
	while(L<=R) {
		int mid=L+R>>1;
		if(check(mid,r)) l=mid,L=mid+1;
		else R=mid-1;
	}
	print(l,r);
	return 0;
}