#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll p[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ll sum=0;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		sum+=(p[i]-(i-1));
	}
	sort(p+1,p+n+1);
	for(int i=2; i<=n ;i++){
		if(p[i]==p[i-1]){
			p[i-1]--;
			break;
		}
	}
	for(int i=2; i<=n ;i++){
		if(p[i]==p[i-1] || p[i-1]<0){
			cout << "cslnb\n";
			return 0;
		}
	}
	if(sum%2) cout << "sjfnb\n";
	else cout << "cslnb\n";
}