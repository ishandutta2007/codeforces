#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 2e5+5, inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

ii arr[ms];
int ans[ms];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = ii(x, i);
	}
	for(int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(arr[x].first > arr[y].first) ans[x]--;
		else if(arr[y].first > arr[x].first) ans[y]--; 
	}
	//for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	//cout << '\n';
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) ans[arr[i].second] += i;
	//for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	//cout << '\n';
	int ultDup = 0;
	for(int i = 1; i < n; i++) {
		if(arr[i].first == arr[ultDup].first) {
			ans[arr[i].second] -= (i - ultDup);
		} else ultDup = i;
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}