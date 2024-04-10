#include <bits/stdc++.h>

using namespace std;

int a[5005], b[5005];
pair<int, int> p[5005];

int main(){
	int n;
	cin >> n;
	int d=0;
	
	for(int i=0; i < n; ++i){
		cin >> a[i] >> b[i];
		p[i]=make_pair(a[i], b[i]);
	}
	sort(p, p+n);
	for(int i=0; i < n; ++i){
		if(p[i].second >= d)
			d=p[i].second;
		else
			d=p[i].first;
	}
	cout << d << endl;
}