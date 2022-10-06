#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=510000,inf=1e9,mod=998244353;
int n,a[1005][1005];
ll realsqrt(ll x){
	ll tmp=sqrt(x);
	while(tmp*tmp>x)tmp--;
	while(tmp*tmp<x)tmp++;
	return tmp;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int a1=realsqrt(1ll*a[1][2]*a[1][3]/a[2][3]);
	cout<<a1<<' ';
	for(int i=2;i<=n;i++){
		cout<<a[1][i]/a1<<' ';
	}
}