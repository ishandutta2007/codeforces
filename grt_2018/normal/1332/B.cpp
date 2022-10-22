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

const int nax = 1000+10;
int t,n;
int a[nax];
int c[nax];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			c[i] = 0;
		}
		int id = 1;
		for(int i=2; i<=50; i++) {
			vi v = {};
			for(int j=1; j<=n; j++) {
				if(c[j]==0&&a[j]%i==0) v.PB(j);
			}
			if((int)v.size()>0) {
				for(auto x:v) c[x] = id;
				id++;
			}
		}
		cout<<id-1<<"\n";
		for(int i=1; i<=n; i++) {
			cout<<c[i]<<" ";
		}
		cout<<"\n";
	}
	
}