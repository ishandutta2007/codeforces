#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i) scanf("%d",a+i);
	int cur=1,res=1;
	for(i=1;i<n;++i){
		if(a[i]==a[i-1]){
			cur=0;
		}
		++cur;
		res=max(res,cur);
	}
	printf("%d\n",res);
	return 0;
}