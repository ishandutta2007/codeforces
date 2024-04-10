#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,X,Y,mi=1e9;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int j=(n+i-1)/i;
		if(i+j<mi)mi=i+j,X=i,Y=j;
	}
	for(int i=X;i>=1;i--){
		for(int j=1;j<=Y;j++){
			int u=(i-1)*Y+j;
			if(u<=n)cout<<u<<' ';
		}
	}
}