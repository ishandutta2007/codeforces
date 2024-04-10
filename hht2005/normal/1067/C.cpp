#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n/3;i++)
		printf("%d %d\n",1,i*2);
	for(int i=1;i<=n/3;i++)
		printf("%d %d\n",2,i*2+1);
	for(int i=1;i<=n/3;i++)
		printf("%d %d\n",3,i*2);
	for(int i=1;i<=n%3;i++)
		printf("%d %d\n",4,i*2);
	return 0;
}