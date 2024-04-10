#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int long long
#define rep(i,b) for(int i=0;i<b;i++)
#define repn(i, b) for(int i=1;i<=b;i++)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#define mp make_pair
#define a first
#define b second

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
template<class t>
using vc = vector<t>;
using P=pair<int,int>;

template<typename flow_t, typename cost_t>
struct PD{
	const cost_t INF;
	
	struct edge{
		int to;
		flow_t cap;
		cost_t cost;
		int rev;
		bool isrev;
	};
	
	vc<vc<edge>>g;
	vc<cost_t>pot, min_cost;
	vc<int>prevv, preve;
	
	PD(int v): g(v), INF(numeric_limits<cost_t>::max()){}
	
	void add_edge(int from, int to, flow_t cap, cost_t cost){
		g[from].eb((edge){to, cap, cost, (int)g[to].size(), false});
		g[to].eb((edge){from, 0, -cost, (int)g[from].size()-1, true});
	}
	
	cost_t min_cost_flow(int s, int t, flow_t f){
		int V = (int)g.size();
		cost_t ret = 0;
		using pi = pair<cost_t, int>;
		priority_queue<pi,vc<pi>,greater<pi>>que;
		pot.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);
		
		while(f > 0){
			min_cost.assign(V, INF);
			que.emplace(0,s);
			min_cost[s] = 0;
			while(!que.empty()){
				pi p = que.top(); que.pop();
				if(min_cost[p.b] < p.a) continue;
				rep(i,g[p.b].size()){
					edge &e = g[p.b][i];
					cost_t nextcs = min_cost[p.b] + e.cost + pot[p.b] - pot[e.to];
					if(e.cap > 0 && min_cost[e.to] > nextcs){
						min_cost[e.to] = nextcs;
						prevv[e.to] = p.b;
						preve[e.to] = i;
						que.emplace(min_cost[e.to], e.to);
					}
				}
			}
			if(min_cost[t] == INF) return -1;
			rep(v, V){
				pot[v] += min_cost[v];
			}
			flow_t addf = f;
			for(int v=t;v!=s;v=prevv[v]){
				chmin(addf, g[prevv[v]][preve[v]].cap);
			}
			f -= addf;
			ret += addf * pot[t];
			
			for(int v=t;v!=s;v=prevv[v]){
				edge &e = g[prevv[v]][preve[v]];
				e.cap-=addf;
				g[v][e.rev].cap+=addf;
			}
		}
		return ret;
	}
};
void solve(){
	int d, n; cin >> d >> n;
	vc<string>v(n);
	vc<int>cnt(n, 0);
	rep(i, n){
		cin >> v[i];
		rep(j, d) cnt[i] += v[i][j]=='1';
	}
	PD<int, int> p(2*n+5), q(2*n+5);
	rep(i, n){
		p.add_edge(2*n+2, i, 1, 0);
		p.add_edge(i+n, 2*n+3, 1, d-cnt[i]);
		q.add_edge(2*n+2, i, 1, 0);
		q.add_edge(i+n, 2*n+3, 1, d-cnt[i]);
	}
	rep(i, n){
		rep(j, n){
			if(i == j) continue;
			rep(a, d) if(v[j][a] == '1' && v[i][a] == '0') goto bad;
			p.add_edge(i, j+n, 1, 0);
			q.add_edge(i, j+n, 1, 0);
			bad:;
		}
	}
	P zan = mp(0, 0);
	int cur = 0;
	for(int i=1;i<=n;i++){
		auto add = p.min_cost_flow(2*n+2, 2*n+3, 1);
		if(add == -1) break;
		cur += add;
		chmax(zan, mp(d*i-cur+i, i));
	}
	
	//cout << zan << endl;
	q.min_cost_flow(2*n+2, 2*n+3, zan.b);
	
	int cntt = 0;
	vc<int>in(n);
	vc<int>go(n,-1);
	rep(i, n){
		for(auto x:q.g[i]){
			if(n <= x.to && x.to < 2*n && !x.isrev && x.cap == 0){
				go[i] = x.to - n;
				cntt ++;
				in[x.to-n] ++;
			}
		}
	}
	assert(cntt == zan.b);
	
	vc<int>vis(n);
	vc<int>ret;
	rep(i, n){
		if(vis[i] || in[i]) continue;
		vc<int>ch;
		int cur = i;
		while(1){
			ch.pb(cur);
			if(go[cur] == -1) break;
			cur = go[cur];
		}
		reverse(ch.begin(), ch.end());
		cur = 0;
		for(int i=0;i<ch.size();i++){
			int nxt = 0;
			for(int j=0;j<d;j++) if(v[ch[i]][j] == '1') nxt |= (1<<j);
			assert(cur < nxt && (cur & nxt) == cur);
			nxt ^= cur;
			int zp = nxt;
			while(nxt){
				int w = __lg(nxt);
				ret.pb(w);
				nxt ^= 1<<w;
			}
			cur ^= zp;
		}
		ret.pb(-1);
	}
	ret.pop_back();
	cout << ret.size() << '\n';
	rep(i, ret.size()){
		if(ret[i] == -1)  cout << "R";
		else cout<<ret[i];
		cout << (i+1==ret.size()?'\n':' ');
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	solve();
}