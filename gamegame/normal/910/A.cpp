#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int ok[101];
char a[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		ok[i]=1e9;
	}
	ok[1]=0;
	for(int i=2; i<=n ;i++){
		if(a[i]=='0') continue;
		for(int j=max(1,i-m); j<i ;j++){
			ok[i]=min(ok[i],ok[j]+1);
		}
	}
	if(ok[n]==1e9) cout << -1 << endl;
	else cout << ok[n] << endl;
}