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

const int nax = 300*1000+10;
int n;
int a[nax];
int p,k;
pi Q[nax];

void wstaw(pi x) {
	while(k>p&&Q[k-1].ST<=x.ST) {
		k--;
		Q[k] = {0,0};
	}
	Q[k++] = x;
}

void usun(int x) {
	if(Q[p].ND==x) p++;
}

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[n+i]=a[2*n+i]=a[i];
	}
	int wsk = 0;
	for(int i=1; i<=n; i++) {
		while(wsk+1<=3*n&&(Q[p].ST-1)/2+1<=a[wsk+1]) {
			wsk++;
			wstaw({a[wsk],wsk});
		}
		if(wsk-i+1>=2*n) cout<<"-1 ";
		else cout<<wsk-i+1<<" ";
		usun(i);
	}
		
	
}