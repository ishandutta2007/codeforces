#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

vector<int> adj[3005];
vector<int> inadj[3005];
//map<pair<int, int>, long long> in;
//map<pair<int, int>, long long> out;
long long in[3005][3005];
long long out[3005][3005];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a;--b;
		for(int j=0; j < adj[a].size(); ++j){
			++in[b][adj[a][j]];
			++in[adj[a][j]][b];
		}
		adj[a].push_back(b);
		for(int j=0; j < inadj[b].size(); ++j){
			++out[a][inadj[b][j]];
			++out[inadj[b][j]][a];
		}
		inadj[b].push_back(a);
	}
	long long ans=0;
	//for(auto it=in.begin(); it != in.end(); ++it){
	//	ans += it->second*out[it->first];
	//}
	for(int i=0; i < n; ++i)
		for(int j=i+1; j < n; ++j)
			ans += in[i][j]*out[i][j];
	for(int i=0; i < n; ++i){
		set<int> sIn;
		set<int> sOut;
		for(int j=0; j < adj[i].size(); ++j)
			sOut.insert(adj[i][j]);
		for(int j=0; j < inadj[i].size(); ++j)
			sIn.insert(inadj[i][j]);
		vector<int> v(max(sIn.size(), sOut.size()));
		auto it = set_intersection(sIn.begin(), sIn.end(), sOut.begin(), sOut.end(), v.begin());
		int num=it-v.begin();
		ans -= (num*(num-1))/2;
		/*in.clear();
		out.clear();
		for(int j=0; j < adj[i].size(); ++j)
			for(int k=j+1; k < adj[i].size(); ++k){
				in[make_pair(adj[i][j], adj[i][k])]++;
				in[make_pair(adj[i][j], adj[i][k])]++;
			}
		for(int j=0; j < inadj[i].size(); ++j)
			for(int k=j+1; k < inadj[i].size(); ++k){
				out[make_pair(inadj[i][j], inadj[i][k])]++;
				out[make_pair(inadj[i][k], inadj[i][j])]++;
			}
		for(auto it=in.begin(); it != in.end(); ++it){
			ans -= it->second*out[it->first];
		}*/
	}
	cout << ans << endl;
}