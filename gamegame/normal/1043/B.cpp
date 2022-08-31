#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n;
ll a[1001];
ll x[1001];
vector<int>ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=i ;j++) x[j]=a[j]-a[j-1];
		bool ok=true;
		for(int j=i+1; j<=n ;j++){
			if(a[j]-a[j-1]!=x[(j-1)%i+1]) ok=false;
		}
		if(ok) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(auto id:ans) cout << id << ' ';
	cout << endl;
}