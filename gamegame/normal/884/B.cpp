#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n,x;
int a[200001];
int t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> x;
	int sum=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sum+=n-1;
	if(sum==x) cout << "YES\n";
	else cout << "NO\n";
}