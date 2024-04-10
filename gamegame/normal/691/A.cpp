#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n;
	int a[n+1],b[n+1];
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		cnt+=a[i];
	}
	if(n>=2 && cnt==n-1 || n==1 && cnt==1) cout << "YES\n";
	else cout << "NO\n";
}