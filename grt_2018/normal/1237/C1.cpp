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

struct Point {
	int x,y,z,id;
	bool operator < (const Point &P) const {
		if(P.x==x) {
			if(P.y==y) return z<P.z;
			return y<P.y;
		}
		return x<P.x;
	}
};

const int nax = 50*1000+10;
int n;
Point p[nax];
vector<pi> ans;
vector<Point> last2;

void solve2D(int s,int e) {
	vector<Point> last = {};
	for(int j=s,i=s; i<=e; i = j) {
		while(j+1<=e&&p[j+1].y==p[j].y) {
			ans.emplace_back(p[j].id,p[j+1].id);
			j+=2;
		}
		if(j<=e) last.PB(p[j]);
		j++;
	}
	for(int i=0; i+1<(int)last.size(); i+=2) {
		ans.emplace_back(last[i].id,last[i+1].id);
	}
	if((int)last.size()&1) last2.PB(last.back());
}

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>p[i].x>>p[i].y>>p[i].z;
		p[i].id = i;
	}
	sort(p+1,p+n+1);
	for(int j=1,i=1; i<=n; i=j) {
		while(j+1<=n&&p[j].x==p[j+1].x) {
			j++;
		}
		//cout<<i<<" "<<j<<"\n";
		solve2D(i,j);
		j++;
	}
	for(int i=0; i+1<(int)last2.size(); i+=2) {
		ans.emplace_back(last2[i].id,last2[i+1].id);
	}
	for(auto w:ans) {
		cout<<w.ST<<" "<<w.ND<<"\n";
	}
	
}