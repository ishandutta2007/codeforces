#include <bits/stdc++.h>
using namespace std;

struct Event{
	int when, type, ind;
	Event(){}
	Event(int iw, int it, int ii){
		when = iw; type = it; ind = ii;
	}
	bool operator<(const Event &a) const{
		if(when != a.when)return when < a.when;
		if(type != a.type)return type < a.type;
		return ind < a.ind;
	}
};

const int N = 100005;
const int mod = 1000000007;

int l[N], r[N];
vector<Event> events;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		events.push_back(Event(l[i], 1, i));
		events.push_back(Event(r[i] + 1, 0, i));
	}
	sort(events.begin(), events.end());
	long long answer = 0;
	multiset<int> closed;
	for(auto e : events){
		if(e.type == 0){
			closed.insert(e.when - 1);
		}else if(closed.empty()){
			(answer += x + y*1LL*(r[e.ind] - l[e.ind])) %= mod;
		}else{
			int prev = *closed.rbegin();
			if((e.when - prev)*1LL*y < x){
				closed.erase(closed.find(prev));
				(answer += (r[e.ind] - prev)*1LL*y) %= mod;
			}else{
				(answer += x + y*1LL*(r[e.ind] - l[e.ind])) %= mod;	
			}
		}
	}
	cout << answer << '\n';

	return 0;
}