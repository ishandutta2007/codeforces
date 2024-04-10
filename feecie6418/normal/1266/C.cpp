#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1)return puts("0"),0;
	if(m==1){
		for(int i=1;i<=n;i++)cout<<i+1<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<i*(j+n)<<' ';
		puts("");
	}
}