#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = (1<<21)+10;
int t,g,h;
int a[nax], lft[nax];
vi mov;

int which(int x) {
	int l = 2*x, r = 2*x+1;
	if(x>=(1<<g)) return x;
	if(a[l]>a[r]) {
		return which(l);
	} else {
		return which(r);
	}
}

void rem(int x) {
	int l = 2*x, r = 2*x+1;
	if(a[l]==0&&a[r]==0) a[x] = 0;
	else {
		if(a[l]>a[r]) {
			a[x] = a[l];
			rem(l);
		} else {
			a[x] = a[r];
			rem(r);
		}
	}
}

void sol(int x) {
	if(a[x]==0) return;
	int w = which(x);
	while(lft[w]>0) {
		//cout << x<< " " <<w << " "<<lft[w]<<"\n";
		lft[w]--;
		rem(x);
		w = which(x);
		mov.PB(x);
	}
	sol(2*x);
	sol(2*x+1);
}

int main() {_
	cin >> t;
	while(t--) {
		cin >> h >> g;
		for(int i = (1<<h); i < (1<<(1+h)); i++) a[i]  = 0;
		for(int i = 1; i < (1<<h); ++i) cin >> a[i];
		for(int i = (1<<g); i<(1<<(g+1)); ++i) lft[i] = (1<<(h-g))-1;
		ll sum = 0;
		mov.clear();
		sol(1);
		for(int i=1; i < (1<<g); ++i) sum += a[i];
		cout << sum <<"\n";
		for(auto it:mov) cout<<it<<" ";
		cout<<"\n";
	}
	
}