#include<bits/stdc++.h>
using namespace std;
int n,tests,k;
int main(){
	for(scanf("%d",&tests);tests;tests--){
		scanf("%d%d",&n,&k);	
		int tmp=k/(n-1);
		if(k%(n-1)==0)printf("%d\n",tmp*n+k%(n-1)-1);
		else printf("%d\n",tmp*n+k%(n-1));
	}
	return 0;
}