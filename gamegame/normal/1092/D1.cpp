#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ll sum=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]%=2;
		if(a[i]%2==1){
			if(i%2==1) sum++;
			else sum--;
		}
	}
	if(sum<0 || sum>1) cout << "NO\n";
	else if(n%2==0 && sum!=0) cout << "NO\n";
	else cout << "YES\n";
}