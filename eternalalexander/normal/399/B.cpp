#include <cstdio>

int main() {
	int n; scanf("%d", &n);
	int t1, t2, t3;
	char stack[100];
	scanf("%s", stack);
	long long ans=0;
	long long f[100]; f[0]=0;
	n+=1; stack[n-1]='R';
	for (int i=1;i<=n;++i) {
		f[i]=(f[i-1]<<1)+1;
	}
	t1=0;
	for (int i=1;i<=n;++i) {
		if (stack[i-1]=='R'&&t1!=0) {
			//printf("%d %d\n", t1, t2);
			ans+=f[t1]<<(t2-1);
			t1=0;
		}
		if (stack[i-1]=='B') {
			if (t1==0) t2=i; 
			t1+=1;
		}
	}printf("%lld", ans);
	return 0;
}