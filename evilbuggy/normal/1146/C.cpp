#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int findMax(int n, int v, int l, int r){
	cout<<1<<" "<<(r-l+1) - (l <= v && v <= r);
	cout<<" "<<v;
	for(int i = l; i <= r; i++){
		if(i != v)cout<<" "<<i;
	}
	cout<<endl;
	int t;
	cin>>t;
	return t;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int mx = findMax(n, 1, 1, n);
		int l = 2, r = n;
		while(l < r){
			int m = l + (r - l)/2;
			int tmp = findMax(n, 1, l, m);
			if(tmp == mx){
				r = m;
			}else{
				l = m + 1;
			}
		}
		cout<<-1<<" "<<findMax(n, l, 1, n)<<endl;
	}

	return 0;
}