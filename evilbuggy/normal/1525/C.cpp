#include <bits/stdc++.h>
using namespace std;

struct Robot{
	int x, dir, i, ans;
};

void process(vector<Robot> &v, int m){
	deque<int> vec;
	for(int i = 0; i < v.size(); i++){
		if(vec.empty()){
			vec.push_back(i);
		}else{
			int j = vec.back();
			if(v[j].dir == 1 && v[i].dir == 0){
				vec.pop_back();
				int dist = v[i].x - v[j].x;
				v[i].ans = dist >> 1;
				v[j].ans = dist >> 1;
			}else{
				vec.push_back(i);
			}
		}
	}
	while(vec.size() >= 2 && v[vec[0]].dir == 0 && v[vec[1]].dir == 0){
		int i0 = vec[0];
		int i1 = vec[1];
		vec.pop_front();
		vec.pop_front();
		int x = v[i0].x;
		int y = v[i1].x;
		v[i0].ans = x + (y - x)/2;
		v[i1].ans = x + (y - x)/2;
	}
	int sz = vec.size();
	while(vec.size() >= 2 && v[vec[sz - 1]].dir == 1 && v[vec[sz - 2]].dir == 1){
		int i0 = vec[sz - 1];
		int i1 = vec[sz - 2];
		vec.pop_back();
		vec.pop_back();
		int x = m - v[i0].x;
		int y = m - v[i1].x;
		v[i0].ans = x + (y - x)/2;
		v[i1].ans = x + (y - x)/2;
		sz -= 2;
	}
	assert(vec.size() <= 2);
	if(vec.size() == 2){
		assert(v[vec[0]].dir == 0 && v[vec[1]].dir == 1);
		int i = vec[0];
		int j = vec[1];
		int x = v[i].x;
		int y = m - v[j].x;
		v[i].ans = (m + x + y)/2;
		v[j].ans = (m + x + y)/2;
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<Robot> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].x;
		v[i].i = i;
		v[i].ans = -1;
	}
	for(int i = 0; i < n; i++){
		char ch;
		cin >> ch;
		if(ch == 'L')v[i].dir = 0;
		else v[i].dir = 1;
	}
	sort(v.begin(), v.end(), [&](Robot a, Robot b){
		return a.x < b.x;
	});
	vector<Robot> e, o;
	for(int i = 0; i < n; i++){
		if(v[i].x&1)o.push_back(v[i]);
		else e.push_back(v[i]);
	}
	process(e, m);
	process(o, m);
	vector<int> ans(n);
	for(auto r : e){
		ans[r.i] = r.ans;
	}
	for(auto r : o){
		ans[r.i] = r.ans;
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}