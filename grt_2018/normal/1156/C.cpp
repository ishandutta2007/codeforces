#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n,z;
int t[nax];

bool checkq(int x) {
	for(int i=0; i<x;i++) {
		if(t[n-x+i]-t[i]<z) {
			return 0;
		}
	}
	return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>z;
    for(int i=0; i<n;i++) {
		cin>>t[i];
	}
	sort(t,t+n);
	int pocz=0,kon=n/2,sr;
	while(pocz<=kon) {
		sr=(pocz+kon)/2;
		if(checkq(sr)) {
			pocz=sr+1;
		}
		else {
			kon=sr-1;
		}
	}
	cout<<pocz-1;
}