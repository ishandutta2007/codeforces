#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	printf("0 0\n1 0\n0 1\n");
	for(int i = 1;i<=n;i++){
		printf("%d %d\n%d %d\n%d %d\n",i,i,i+1,i,i,i+1);
	}
	printf("%d %d\n",n+1,n+1);
	return 0;
}