#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int t=n/111,FL=0;
		for(int i=0;i<=1000&&t>=0&&FL==0;i++) {
			if((n-t*111)%11==0)FL=1;
			t--;
		}
		puts(FL?"YES":"NO");
	}
	return 0;
}