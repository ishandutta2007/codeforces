#include<bits/stdc++.h>
using namespace std;
long long a[10010];
int I[30010],J[30010],v[30010],m;
void op(int i,int j,int x) {
	if(x==0)return;
	I[++m]=i;
	J[m]=j;
	v[m]=x;
	a[i]-=1ll*i*x;
	a[j]+=1ll*i*x;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		m=0;
		long long sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%lld",a+i);
			sum+=a[i];
		}
		if(sum%n!=0) {
			puts("-1");
			continue;
		}
		sum/=n;
		for(int i=2;i<=n;i++) {
			if(a[i]%i!=0)op(1,i,(a[i]/i+1)*i-a[i]);
			op(i,1,a[i]/i);
		}
		for(int i=n;i>1;i--)op(1,i,sum);
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
			printf("%d %d %d\n",I[i],J[i],v[i]);
	}
	return 0;
}