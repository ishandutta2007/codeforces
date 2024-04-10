#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn],b[maxn],sk[maxn];
int calc(int L,int R) {
	int top=0;
	for(int i=L+1;i<R;i++) {
		if(a[i]<a[L]||a[i]>a[R])continue;
		if(!top||sk[top]<=a[i])sk[++top]=a[i];
		else sk[upper_bound(sk+1,sk+top+1,a[i])-sk]=a[i];
	}
	return R-L-1-top;
}
int main() {
	int n,m,fl=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		a[i]-=i;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",b+i);
		if(i>1&&a[b[i-1]]>a[b[i]])fl=1;
	}
	if(fl)return puts("-1"),0;
	b[m+1]=n+1;
	a[0]=-1e9;
	a[n+1]=1e9;
	for(int i=1;i<=m+1;i++)
		ans+=calc(b[i-1],b[i]);
	printf("%d\n",ans);
	return 0;
}