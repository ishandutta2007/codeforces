#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],C[N],pos[N],L[N],top,M;
map<int,int>S;
void opt(int a,int b) {
	pos[++M]=a;
	C[M]=b;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,FL=1;
		top=M=0;
		S.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			S[a[i]]^=1;
		}
		for(int i=1;i<=n;i++)
			if(S[a[i]])FL=0;
		if(FL==0)puts("-1");
		else {
			int sum=0;
			while(n) {
				int r=0;
				for(int i=2;i<=n;i++)
					if(a[1]==a[i]) {
						r=i;
						break;
					}
				for(int i=2;i<r;i++)
					opt(sum+i+r-2,a[i]);
				for(int i=2,j=r-1;i<j;i++,j--)
					swap(a[i],a[j]);
				for(int i=r;i>=3;i--)
					a[i]=a[i-1];
				for(int i=1;i<=n;i++)
					a[i]=a[i+2];
				L[++top]=2*(r-1);
				sum+=L[top];
				n-=2;
			}
			printf("%d\n",M);
			for(int i=1;i<=M;i++)
				printf("%d %d\n",pos[i],C[i]);
			printf("%d\n",top);
			for(int i=1;i<=top;i++)
				printf("%d ",L[i]);
			puts("");
		}
	}
	return 0;
}