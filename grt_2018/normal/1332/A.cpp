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

int t;
int a,b,c,d;
int x,y,x11,y11,x21,y21;

int main() {_
	cin>>t;
	while(t--) {
		cin >> a>> b >>c>>d;
		cin>>x>>y>>x11>>y11>>x21>>y21;
		int m1 = b-a, m2 = d-c;
		if((b>0||a>0)&&x11==x21) {
			cout<<"No\n";
			continue;
		}
		if((c>0||d>0)&&y11==y21) {
			cout<<"No\n";
			continue;
		}
		x+=m1; y+=m2;
		if(x11<=x&&x<=x21&&y11<=y&&y<=y21) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
		
	
}