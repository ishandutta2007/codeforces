#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = 1e9;
long long big_inf = 1e18;	
int m1, m2;
string t;


int find(int l, int r){
	if (r < l){
		return -1;
	}

	if (l == r){
		return l;
	}

	int k = (r - l + 1) / 4;
	m1 = l + k;
	m2 = r - k;
	cout << 1 << " " << m1 << " " << m2 << endl;
	cin >> t;

	if (t == "TAK"){
		return find(l, (m1 + m2) / 2);
	}
	else{
		return find((m1 + m2) / 2 + 1, r);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;

	int mid = find(1, n);
	int l = find(1, mid - 1);
	int r = find(mid + 1, n);

	if (l == -1){
		cout << 2 << " " << mid << " " << r << endl;
		return 0;
	}

	cout << 1 << " " << l << " " << mid << endl;
	cin >> t;
	if (t == "TAK"){
		cout << 2 << " " << mid << " " << l << endl;
		return 0;
	}

	cout << 2 << " " << mid << " " << r;
	return 0;
}