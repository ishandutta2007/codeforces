#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int main() {
	int T,n,a;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int I=0;
		for(int i=2;i<=n;i++) {
			printf("? %d 1\n",i-1);
			for(int j=1;j<i;j++)printf("%d ",j);puts("");
			printf("%d\n",i);
			fflush(stdout);
			scanf("%d",&a);
			if(a) {
				I=i;
				break;
			}
		}
		int l=1,r=I-2;
		while(l<=r) {
			int mid=(l+r)>>1;
			printf("? %d 1\n",mid);
			for(int i=1;i<=mid;i++)printf("%d ",i);puts("");
			printf("%d\n",I);
			fflush(stdout);
			scanf("%d",&a);
			if(a)r=mid-1;
			else l=mid+1;
		}
		ans.clear();
		for(int i=1;i<I;i++)
			if(i!=r+1)ans.push_back(i);
		for(int i=I+1;i<=n;i++) {
			printf("? 1 1\n%d\n%d\n",i,I);
			fflush(stdout);
			scanf("%d",&a);
			if(!a)ans.push_back(i);
		}
		printf("! %d",int(ans.size()));
		for(int i:ans)
			printf(" %d",i);
		puts("");
		fflush(stdout);
	}
	return 0;
}