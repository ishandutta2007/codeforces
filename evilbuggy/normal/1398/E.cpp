#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 25;
int n, m, sx, sy, type[N], d[N], val[N];
pair<int, ll> f[2][N];

void pre(){
	vector<int> vec;
	for(int i = 1; i <= n; i++){
		vec.push_back(abs(d[i]));
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	m = vec.size();
	for(int i = 0; i < m; i++){
		val[i + 1] = vec[i];
	}
	for(int i = 1; i <= n; i++){
		if(d[i] > 0){
			d[i] = lower_bound(val + 1, val + m + 1, d[i]) - val;
		}else{
			d[i] = -(lower_bound(val + 1, val + m + 1, -d[i]) - val);
		}
	}
}

inline void update(int j, int i, int x, ll y){
	while(i <= m){
		f[j][i].first += x;
		f[j][i].second += y;
		i += i&(-i);
	}
}

inline pair<int, ll> query(int j, int i){
	pair<int, ll> ret = {0, 0};
	while(i){
		ret.first += f[j][i].first;
		ret.second += f[j][i].second;
		i &= (i - 1);
	}
	return ret;
}

inline ll func(int k){
	ll ret = 0;
	if(sx != k){
		int lo = 1, hi = m;
		while(lo < hi){
			int mi = lo + (hi - lo)/2;
			if(query(0, mi).first < sx - k)lo = mi + 1;
			else hi = mi;
		}
		ret += query(0, m).second - query(0, lo).second;
	}else{
		ret += query(0, m).second;
	}

	{
		int lo = 1, hi = m;
		while(lo < hi){
			int mi = lo + (hi - lo)/2;
			if(query(1, mi).first < k)lo = mi + 1;
			else hi = mi;
		}
		ret -= query(1, lo).second;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>type[i]>>d[i];
	}
	pre();
	ll sum = 0;
	sx = 0, sy = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		if(type[i] == 0){
			if(d[i] > 0){
				sx++;
				sum += val[d[i]];
				update(0, d[i], 1, val[d[i]]);
			}else{
				sx--;
				d[i] = -d[i];
				sum -= val[d[i]];
				update(0, d[i], -1, -val[d[i]]);
			}
		}else{
			if(d[i] > 0){
				sy++;
				sum += 2*val[d[i]];
				update(1, d[i], 1, val[d[i]]);
			}else{
				sy--;
				d[i] = -d[i];
				sum -= 2*val[d[i]];
				update(1, d[i], -1, -val[d[i]]);
			}
		}
		if(sy == 0){
			cout<<sum<<'\n';
			continue;
		}
		int lo = 1, hi = min(sx, sy);
		while(lo < hi){
			int mi = lo + (hi - lo)/2;
			if(func(mi) < func(mi + 1))lo = mi + 1;
			else hi = mi;
		}
		// cout<<i<<" "<<func(lo)<<endl;
		cout<<sum + func(lo)<<'\n';
	}


	return 0;
}