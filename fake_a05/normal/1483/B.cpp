#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int>
#define ii pair<int, int>
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2e5 + 5, mod = 1e9 + 7;

int tc;
int N, M;
int genre[maxN], head[maxN], root[maxN];
set<int> av;
vi ans;

int getRoot(int i){
	if(root[i] < 0) return i;
	return root[i] = getRoot(root[i]);
}

set<int> :: iterator go(set<int> & S, set<int> :: iterator it){
	if(next(it) == S.end()) return S.begin();
	return next(it);
}

void merge(int f, int t){
	f = getRoot(f), t = getRoot(t);
	if(f == t) return;
	int Thead = head[t];
	if(root[t] > root[f]) swap(f, t);
	root[t] += root[f];
	root[f] = t;
	head[t] = Thead;
}

void prep(){
	ans.clear();
	av.clear();
	loop(i, 1, N){
		head[i] = i;
		root[i] = -1;
		av.insert(i);
	}
	for(set<int> :: iterator it = av.begin(); it != av.end() ; ++it){
		auto nx = go(av, it);
		if(__gcd(genre[* it], genre[* nx]) != 1){
			merge(* it, * nx);
		} 
	}
}

void proc(){
	int now = 1;
	while(1){
		if(av.empty()) return;
		now = head[getRoot(now)];
//		cout << now << sp;
		auto it = av.find(now);
		auto nx = go(av, it);
//		cout << (* nx)<< endl;
		if(__gcd(genre[* it], genre[* nx]) == 1) {
//			cout <<"case 1" << endl;
			ans.eb(* nx);
			auto nxx = go(av, nx);
			now = (* nxx);
			av.erase(nx);
//			cout  << "go to " << now << endl;
		}
		else if(getRoot(* it) == getRoot(* nx)) return;
		else{
//			cout << "case2" << endl;
			merge(now, * nx);
			now = * nx;
		}
	}
}

void input(){
	cin >> N;
	loop(i, 1, N){
		cin >> genre[i];
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while(tc--){
		input();
			prep();
		proc();
		cout << ans.size() << sp;
		for(int i: ans) cout << i << sp;
		cout << endl;
	}
}