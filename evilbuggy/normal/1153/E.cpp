#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int query(int x1, int y1, int x2, int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int t;
	cin>>t;
	return t;
}

pair<int, int> findRows(int n){
	int ind1 = -1, ind2 = n;
	for(int i = 1; i < n; i++){
		int t = query(1, 1, i, n);
		if(t&1){
			ind1 = i;
			break;
		}
	}
	if(ind1 == -1)return {ind1, ind2};
	for(int i = ind1 + 1; i < n; i++){
		int t = query(1, 1, i, n);
		if(!(t&1)){
			ind2 = i;
			break;
		}
	}
	return {ind1, ind2};
}

pair<int, int> findCols(int n){
	int ind1 = -1, ind2 = n;
	for(int i = 1; i < n; i++){
		int t = query(1, 1, n, i);
		if(t&1){
			ind1 = i;
			break;
		}
	}
	if(ind1 == -1)return {ind1, ind2};
	for(int i = ind1 + 1; i < n; i++){
		int t = query(1, 1, n, i);
		if(!(t&1)){
			ind2 = i;
			break;
		}
	}
	return {ind1, ind2};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	pair<int, int> rows = findRows(n);
	if(rows.first == -1){
		pair<int, int> cols = findCols(n);
		int y1 = cols.first;
		int y2 = cols.second;
		int l = 1, r = n;
		while(l < r){
			int m = l + (r - l)/2;
			int t = query(1, y1, m, y1);
			if(t&1){
				r = m;
			}else{
				l = m + 1;
			}
		}
		int x1 = l;
		l = 1, r = n;
		while(l < r){
			int m = l + (r - l)/2;
			int t = query(1, y2, m, y2);
			if(t&1){
				r = m;
			}else{
				l = m + 1;
			}
		}
		int x2 = l;
		cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	}else{
		int x1 = rows.first;
		int x2 = rows.second;
		int l = 1, r = n;
		while(l < r){
			int m = l + (r - l)/2;
			int t = query(x1, 1, x1, m);
			if(t&1){
				r = m;
			}else{
				l = m + 1;
			}
		}
		int y1 = l;
		l = 1, r = n;
		while(l < r){
			int m = l + (r - l)/2;
			int t = query(x2, 1, x2, m);
			if(t&1){
				r = m;
			}else{
				l = m + 1;
			}
		}
		int y2 = l;
		cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

	}

	return 0;
}