#include<iostream>
using namespace std;
const int mod=998244353;
long long X[5010][5010];
int main(){
	for(int i=0;i<=5000;++i)
	for(int j=0;j<=5000;++j){
		if(i==0||j==0)X[i][j]=1;
		else X[i][j]=(X[i-1][j]+j*X[i-1][j-1])%mod;
	}
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(((X[a][b]*X[a][c])%mod)*X[b][c])%mod;
}