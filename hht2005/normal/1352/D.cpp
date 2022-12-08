#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		int L=2,R=n,las=a[1],t=1,A=a[1],B=0,cnt=1;
		while(L<=R) {
			cnt++;
			int sum=0;
			if(t)while(L<=R&&sum<=las)sum+=a[R--];
			else while(L<=R&&sum<=las)sum+=a[L++];
			las=sum;
			if(t)B+=sum;
			else A+=sum;
			t^=1;
		}
		printf("%d %d %d\n",cnt,A,B);
	}
	return 0;
}