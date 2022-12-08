#include<bits/stdc++.h>
using namespace std;
int main() {
	int q;
	scanf("%d",&q);
	while(q--) {
		int a,b,c1=0,c2=0;
		scanf("%d%d",&a,&b);
		int FL=(a<=b);
		for(int i=0;i<30;i++) {
			if(a>>i&1)c1++;
			if(b>>i&1)c2++;
			if(c1<c2)FL=0;
		}
		puts(FL?"YES":"NO");
	}
	return 0;
}