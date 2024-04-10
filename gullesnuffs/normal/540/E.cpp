#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

map<int, int> M;
vector<int> v;
map<int, int> sorted;

int get(int pos){
	if(M.find(pos) == M.end())
		M[pos]=pos;
	return M[pos];
}

struct Fenwick{
	int f[200005];

	int query(int x){
		int ret=0;
		for(int i=x; i < 200005; i|=(i+1))
			ret += f[i];
		return ret;
	}

	void update(int x, int val){
		for(int i=x; i >= 0; i=(i&(i+1))-1)
			f[i] += val;
	}
} fenwick;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		int a, b;
		scanf("%d%d", &a, &b);
		int a1=get(a);
		int b1=get(b);
		M[a]=b1;
		M[b]=a1;
	}
	for(auto it = M.begin(); it != M.end(); ++it)
		v.push_back(it->second);
	sort(v.begin(), v.end());
	long long ans=0;
	for(int i=0; i < v.size(); ++i){
		sorted[v[i]]=i;
	}
	int i=0;
	for(auto it = M.begin(); it != M.end(); ++it){
		ans += fenwick.query(sorted[it->second]);
		fenwick.update(sorted[it->second], 1);
		++i;
	}
	for(auto it=M.begin(); it != M.end(); ++it){
		if(it->first < it->second){
			auto l1=lower_bound(v.begin(), v.end(), it->first);
			auto l2=lower_bound(v.begin(), v.end(), it->second);
			int left=it->second-it->first-(l2-l1);
			ans += left;
		}
		else{
			auto l1=lower_bound(v.begin(), v.end(), it->first);
			auto l2=lower_bound(v.begin(), v.end(), it->second);
			int left=it->first-it->second-(l1-l2);
			ans += left;
		}
	}
	cout << ans << endl;
}