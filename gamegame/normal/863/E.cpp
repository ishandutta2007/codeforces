#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define fi first
#define se second
pair<pair<int,int>,int>a[200001];
vector<pair<pair<int,int>,int> >lol;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n ;i++){
		if(a[i-1].fi.se>=a[i].fi.se){
			cout << a[i].se << endl;
			return 0;
		}
		if(a[i-1].fi.fi==a[i].fi.fi){
			cout << a[i-1].se << endl;
			return 0;
		}
	}
	for(int i=2; i<n ;i++){
		if(a[i-1].fi.se+1<a[i+1].fi.fi) continue;
		cout << a[i].se << endl;
		return 0;
	}
	cout << -1 << endl;
}