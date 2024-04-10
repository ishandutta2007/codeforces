#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main(){
	ll n, r;
	cin >> n >> r;
	r = r * r;
	vector<pair<ll, ll>>points(n);
	for(ll i=0;i<n;i++) cin >> points[i].first >> points[i].second;
	auto ok = vector<vector<ll>>(n, vector<ll>(n, 0));
	ld p = acos(-1.0L) * 2.0L;
	
	for(ll i=0;i<n;i++){
		ld small = -10, big = 10;
		bool vanish = false;
		for(ll j=0;j<n;j++){
			ll distance = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
			if(distance <= r) continue;
			
			ld X = -(ld)(points[i].first - points[j].first), Y = -(ld)(points[i].second - points[j].second);
			ld direction = atan2(Y, X), rng = asin(sqrt((ld)(r) / (ld)(distance)));
			ld bottom = direction - rng, top = direction + rng;
			bool intersect = false;
			for(ll rot=-1;rot<=1;rot++){
			    if(big-small > 19 and rot) continue;
				ld rot_bottom = bottom + p * rot;
				ld rot_top = top + p * rot;
				if(max(small, rot_bottom) <= min(big, rot_top)){
					small = small < rot_bottom? rot_bottom: small;
					big = big > rot_top? rot_top: big;
					intersect = true;
					break;
				}
			}
			if(!intersect){
				vanish = true;
				break;
			}
		}
		if(vanish) continue;
		for(ll j=0;j<n;j++){
			if(i == j) continue;
			ld X = -(ld)(points[i].first - points[j].first), Y = -(ld)(points[i].second - points[j].second);
			ld direction = atan2(Y, X);
			
			for(ll rot=-1;rot<=1;rot++){
				double rot_direction = direction + p * rot;
				if(small <= rot_direction && rot_direction <= big){
					ok[i][j] = true;
				}
			}
		}
	}
	int result = 0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<i;j++){
			result += ok[i][j] && ok[j][i];
		}
	}
	cout << result << endl;
	return 0;
}