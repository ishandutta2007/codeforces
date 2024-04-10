#include<bits/stdc++.h>
using namespace std;
#define N 505
int main(){
	int n;
	scanf("%d",&n);
	int ok=0;
	for(int i=0;i<n;i++){
		char c[10000];
		int a,b;
		scanf("%s %d %d",c,&a,&b);
		if(a>=2400){
			if(b>a)
			ok=1;
		}
	}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}