#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll x[101];
int main(){
	ios::sync_with_stdio(false);
	int n,d;
	cin >> n >> d;
	for(int i=1; i<=n ;i++){
		cin >> x[i];
	}
	int ans=2;
	for(int i=2; i<=n ;i++){
		if(x[i]-x[i-1]==d*2) ans++;
		else if(x[i]-x[i-1]>d*2) ans+=2;
	}
	cout << ans << endl;
}