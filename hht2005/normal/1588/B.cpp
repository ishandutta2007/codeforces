#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n;
	long long S,k;
	scanf("%d",&T);
	while(T--) {
		int A,B,C;
		A=B=C=-1;
		scanf("%d",&n);
		printf("? %d %d\n",1,n);
		fflush(stdout);
		scanf("%lld",&k);
		int l=1,r=n;
		while(l<=r) {
			int mid=(l+r)>>1;
			printf("? %d %d\n",1,mid);
			fflush(stdout);
			scanf("%lld",&S);
			if(S==0)l=mid+1;
			else r=mid-1;
		}
		A=l-1;
		printf("? %d %d\n",A+1,n);
		fflush(stdout);
		scanf("%lld",&S);
		B=A+k-S+1;
		printf("? %d %d\n",B,n);
		fflush(stdout);
		scanf("%lld",&S);
		printf("? %d %d\n",B+1,n);
		fflush(stdout);
		scanf("%lld",&k);
		printf("! %d %d %lld\n",A,B,B+S-k);
		fflush(stdout);
	}
	return 0;
}