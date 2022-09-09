#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int a[2010];
int g[2010][2010];
int main(){
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],g[i][0]=a[i],k+=(g[i][0]==1);
	if(k){cout<<n-k;return 0;}
	for(int i=1;i<n;++i){
		for(int j=1;j+i<=n;++j)g[j][i]=gcd(g[j][i-1],a[j+i]),k|=(g[j][i]==1);
		if(k){cout<<n+i-1;return 0;}
	}
	cout<<-1;
	return 0;
}