#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&b);
		printf("%d\n",a^b);
	}
}