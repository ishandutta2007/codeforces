#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5 +1;
int a[MAXN],n;
long long sum=0;
bool cmp(int a,int b){return a>b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d ",&a[i]),sum+=a[i];
	sort(a+1,a+1+n,cmp);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		int q;
		scanf("%d",&q);
		printf("%lld\n", sum-a[q]);
	}
	return 0;
}