#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans[105],sum,fu;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum++;
		if(a<0)fu++;
		if(fu==3){
			ans[++m]=sum-1;
			sum=1;
			fu=1;
		}
	}
	ans[++m]=sum;
	cout<<m<<endl;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}