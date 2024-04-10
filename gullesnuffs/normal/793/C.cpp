#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int rx[100005], ry[100005];
int vx[100005], vy[100005];

pair<double, double> getInter(int pos, int v, int b1, int b2){
	if(v == 0){
		if(pos > b1 && pos < b2){
			return make_pair(-INF, INF);
		}
		return make_pair(INF, INF);
	}
	double t1 = ((double)(b1-pos))/v;
	double t2 = ((double)(b2-pos))/v;
	if(t1 > t2)
		swap(t1, t2);
	return make_pair(t1, t2);
}

pair<double, double> intersection(pair<double, double> i1, pair<double, double> i2){
	if(i1 > i2)
		swap(i1, i2);
	if(i1.second <= i2.first)
		return make_pair(INF, INF);
	return make_pair(i2.first, min(i1.second, i2.second));
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int x1, y1, x2, y2;	
	cin >> x1 >> y1 >> x2 >> y2;
	pair<double, double> ans = make_pair(0, INF);
	rep(i,0,n){
		cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
		auto intx = getInter(rx[i], vx[i], x1, x2);
		ans = intersection(ans, intx);
		auto inty = getInter(ry[i], vy[i], y1, y2);
		ans = intersection(ans, inty);
	}
	if(ans.first > 1000000 || ans.second-ans.first < 5e-13){
		cout << "-1" << endl;
	}
	else{
		cout << setprecision(9) << fixed << ans.first << endl;
	}
}