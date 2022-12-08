#include<bits/stdc++.h>
using namespace std;
int k;
void calc(int T) {
	for(int i=1;i<k;i++)
		printf("%d %d\n",T+1,T+i+1);
	for(int i=1;i<k;i++)
		for(int j=1;j<k;j++)
			printf("%d %d\n",T+i+1,T+k+j);
	for(int i=1;i<k;i+=2)
		printf("%d %d\n",T+k+i,T+k+i+1);
}
int main() {
	scanf("%d",&k);
	if(!(k&1)) {
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d %d\n",4*k-2,(4*k-2)*k/2);
	calc(0);
	calc(2*k-1);
	printf("%d %d\n",1,2*k);
	return 0;
}