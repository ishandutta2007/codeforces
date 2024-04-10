
 #include <bits/stdc++.h>

int n, tail=0;
long long ans[100005];

int main() {
	scanf("%d", &n);
	for (int p=1;p*p<=n;++p) {
		//printf("%d %d\n",p, n%p);
		if (n%p==0) {
			ans[++tail]=(long long)(1+n-p+1)*(long long)(n/p)/2;
			int p2=n/p;
			if (p2==p) continue;
			ans[++tail]=(long long)(1+n-p2+1)*(long long)(n/p2)/2;
		}
	}std::sort(ans+1, ans+tail+1);
	for (int i=1;i<=tail;++i) std::cout<<ans[i]<<" ";
	return 0;
}