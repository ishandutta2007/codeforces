#include<bits/stdc++.h>
using namespace std;
int A[300010]={};
int main(){
	int n;
	cin>>n;
	int k=n;
	cout<<1<<" ";
	for(int i=1;i<=n;++i){
		int p;
		scanf("%d",&p);
		A[p]=1;
		while(A[k]&&k>0)k--;
		printf("%d ",i-(n-k)+1);
	}
}