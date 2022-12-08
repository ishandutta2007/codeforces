#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using ll=long long;
int a[N],t[N],I,L,R;
ll W,f[22][N];
void add(int x,int v) {
	x=a[x];
	W-=1ll*t[x]*(t[x]-1)/2;
	t[x]+=v;
	W+=1ll*t[x]*(t[x]-1)/2;
}
ll calc(int l,int r) {
	while(L>l)add(--L,1);
	while(R<r)add(++R,1);
	while(L<l)add(L++,-1);
	while(R>r)add(R--,-1);
	return W;
}
void calc(int l,int r,int L,int R) {
	int mid=(l+r)>>1,p=0;
	for(int i=L;i<=R&&i<=mid;i++) {
		ll t=calc(i,mid)+f[I-1][i-1];
		if(t<f[I][mid]) {
			f[I][mid]=t;
			p=i;
		}
	}
	if(l<mid)calc(l,mid-1,L,p);
	if(r>mid)calc(mid+1,r,p,R);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(I=1;I<=k;I++) {
		memset(t,0,sizeof(t));
		W=0,L=1,R=0;
		calc(1,n,1,n);
	}
	printf("%lld\n",f[k][n]);
	return 0;
}