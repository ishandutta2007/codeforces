#include<iostream>
using namespace std;
int cntx[1001],cnty[1001];
int n,m;
char c;
char a[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c;
			cntx[i]+=(c=='*');
			cnty[j]+=(c=='*');
			a[i][j]=c;
		}
	}
	long long ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(a[i][j]!='*') continue;
			ans+=(max(0,cntx[i]-1))*(max(0,cnty[j]-1));
		}
	}
	cout << ans << endl;
}