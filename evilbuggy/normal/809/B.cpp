#include <bits/stdc++.h>
using namespace std;

int query(int x, int y){
	cout << 1 << " " << x << " " << y << endl;
	string ret;
	cin >> ret;
	return ret == "TAK";
}

int pos1, pos2;

void search(int l, int r){
	if(l == r){
		pos1 = l;
		return;
	}
	int m = (l + r)/2;
	if(query(m, m + 1)){
		search(l, m);
		if(pos2 != -1)return;
		if((r - l + 1)&1){
			if(query(l, r))return;
		}else{
			if(!query(r, l))return;
		}
		int lo = 0, hi = pos1 - l;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			if(query(pos1 - mi, r)){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		pos2 = r - lo;
	}else{
		search(m + 1, r);
		if(pos2 != -1)return;
		if((r - l + 1)&1){
			if(!query(l, r))return;
		}else{
			if(query(r, l))return;
		}
		int lo = 0, hi = r - pos1;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			if(query(pos1 + mi, l)){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		pos2 = l + lo;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	pos1 = pos2 = -1;
	
	search(1, n);
	cout << 2 << " " << pos1 << " " << pos2 << endl;

	return 0;
}