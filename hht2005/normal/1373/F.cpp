#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn],b[maxn],n;
int calc(int x) {
	int las=b[1]-x;
	for(int i=2;i<=n;i++) {
		las=b[i]-(a[i]-las);
		las=min(las,b[i]);
		if(las<0)return -1;
	}
	if(las+x>=a[1])return 0;
	return 1;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)scanf("%d",b+i);
		int L=0,R=min(a[1],b[1]),fl=0;
		while(L<=R&&!fl) {
			int mid=(L+R)>>1,t=calc(mid);
			if(t==0)fl=1;
			if(t==1)L=mid+1;
			if(t==-1)R=mid-1;
		}
		puts(fl?"YES":"NO");
	}
	return 0;
}