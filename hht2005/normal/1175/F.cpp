#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define Pow(n) (1<<(n))
int a[maxn],ans,pre[maxn],las[maxn],f[maxn][20],Log[maxn];
int calc(int l,int r) {
	int L=Log[r-l+1];
	return a[f[l][L]]>a[f[r-Pow(L)+1][L]]?f[l][L]:f[r-Pow(L)+1][L];
}
void solve(int l,int r) {
	if(l>r)return;
	if(l==r) {
		if(a[l]==1)ans++;
		return;
	}
	int mid=calc(l,r),i=l,j=l+a[mid]-1;
	if(j<mid)i+=mid-j,j=mid;
	for(;i<=mid&&j<=r;i++,j++)
		if(pre[j]<i)
			ans++;
	solve(l,mid-1),solve(mid+1,r); 
}
int main() {
	int n;
	Log[0]=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		Log[i]=Log[i>>1]+1;
		f[i][0]=i;
		pre[i]=max(pre[i-1],las[a[i]]);
		las[a[i]]=i;
	}
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n+1-Pow(j);i++)
			f[i][j]=a[f[i][j-1]]>a[f[i+Pow(j-1)][j-1]]?f[i][j-1]:f[i+Pow(j-1)][j-1];
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}