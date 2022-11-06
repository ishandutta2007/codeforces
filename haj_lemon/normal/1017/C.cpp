#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int p=sqrt(n);
	for (int i=p,j=1;i<n+p;i+=p,j+=p){
		i=min(i,n);
		for (int k=i;k>=j;k--) printf("%d ",k);
	}
	return 0;
}