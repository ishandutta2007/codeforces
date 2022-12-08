#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn];
int c[maxn],sum[maxn<<2][27];
void add(int p,int l,int r,int x,int id) {
	if(l==r) {
		sum[p][id]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,id);
	else add(p<<1|1,mid+1,r,x,id);
	sum[p][id]=sum[p<<1][id]+sum[p<<1|1][id];
}
int qry(int p,int l,int r,int id) {
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[p<<1][id]<mid-l+1)return qry(p<<1,l,mid,id);//efe
	else return qry(p<<1|1,mid+1,r,id);
}
int main() {
	int n;//aegeg
	scanf("%d%s",&n,s+1);//dsf
	int cnt=0;
	for(int i=1;i<=n;i++) {
		c[i]=qry(1,1,n,s[i]-'a');
		cnt=max(cnt,c[i]);
		for(int j=0;j<s[i]-'a';j++)
			add(1,1,n,c[i],j);
	}
	printf("%d\n",cnt);
	for(int i=1;i<n;i++)
		printf("%d ",c[i]);//safd
	printf("%d\n",c[n]);
	return 0;
}