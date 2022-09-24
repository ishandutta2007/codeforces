#include<bits/stdc++.h>
using namespace std;
int n,m,p;
vector<int> w[40005];
bitset<10005> ans;
void Modify(int p,int l,int r,int x,int y,int z) {
	if(x<=l&&r<=y)return w[p].push_back(z),void();
	int mid=(l+r)/2;
	if(x<=mid)Modify(p*2,l,mid,x,y,z);
	if(mid<y)Modify(p*2+1,mid+1,r,x,y,z);
}
void GetAns(int p,int l,int r,bitset<10005> t){
	for(int x:w[p])t|=t<<x;
	if(l==r)return ans|=t,void();
	int mid=(l+r)/2;
	GetAns(p*2,l,mid,t);
	GetAns(p*2+1,mid+1,r,t);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,l,r,x; i<=m; i++)scanf("%d%d%d",&l,&r,&x),Modify(1,1,n,l,r,x);
	ans[0]=1,GetAns(1,1,n,ans);
	for(int i=1;i<=n;i++)if(ans[i])p++;
	printf("%d\n",p);
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}