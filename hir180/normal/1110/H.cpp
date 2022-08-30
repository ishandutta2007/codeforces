//Let's join Kaede Takagaki Fun Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}


const int A = 10, SZ = 805;

//fail...strictlysuffixlink
//go...Trie
struct node{
	vector<node*>go;
	vector<int>sum;
	node* fail;
	int id;
	
	node(int len, int id): id(id) {
		go.resize(A, (node*)NULL);
		sum.resize(len, 0);
		fail = (node*)NULL;
	}
};
vector<node*>nd;
string lb, ub;
int n,nxt;

int main(){
	cin >> lb >> ub >> n;
	auto make = [&](){
		node* ret = new node(SZ, nd.size());
		nd.pb(ret);
		return ret;
	};
	node *root = make();
	auto make_pat = [&](string lb, string ub){
		node *le = root, *ri = root;
		bool dif = 0;
		for(int i=0;i<lb.size();i++){
			if(!dif){
				for(int j=lb[i]-'0';j<=ub[i]-'0';j++){
					if(!le->go[j]) le->go[j] = make();
					
					if(i+1 == lb.size() || (j != lb[i]-'0' && j != ub[i]-'0')){
						le->go[j]->sum[lb.size()-i-1] ++;
					}
				}
				if(lb[i] != ub[i]) dif = 1;
			}
			else{
				for(int j=lb[i]-'0';j<A;j++){
					if(!le->go[j]) le->go[j] = make();
					if(i+1 == lb.size() || j != lb[i]-'0'){
						le->go[j]->sum[lb.size()-i-1]++;
					}
				}
				for(int j=0;j<=ub[i]-'0';j++){
					if(!ri->go[j]) ri->go[j] = make();
					if(i+1 == ub.size() || j != ub[i]-'0'){
						ri->go[j]->sum[ub.size()-1-i]++;
					}
				}
			}
			le = le->go[lb[i]-'0'];
			ri = ri->go[ub[i]-'0'];
		}
	};
	
	if(lb.size() == ub.size()) make_pat(lb, ub);
	else{
		string SS(lb.size(), '9');
		make_pat(lb, SS);
		SS = string(ub.size(), '0');
		SS[0] = '1';
		make_pat(SS, ub);
		for(int i=lb.size()+1;i<ub.size();i++){
			repn(b,A-1){
				if(!root->go[b]) root->go[b] = make();
				root->go[b]->sum[i-1]++;
			}
		}
	}
	root->fail = root;
	queue<node*>que;
	
	rep(i,A){
		if(!root->go[i]) root->go[i] = root;
		else {
			root->go[i]->fail = root;
			que.push(root->go[i]);
		}
	}
	
	while(!que.empty()){
		node* q = que.front(); que.pop();
		//
		rep(i,SZ) q->sum[i] += q->fail->sum[i];
		rep(i,A){
			if(!q->go[i]) q->go[i] = q->fail->go[i];
			else{
				q->go[i]->fail = q->fail->go[i];
				que.push(q->go[i]);
			}
		}
	}
	for(auto x:nd){
		rep(i,SZ-1) x->sum[i+1] += x->sum[i];
	}
	int sz = nd.size();
	auto dp = vector<vector<int>>(n+2, vector<int>(sz+2, -INF));
	auto pt = vector<vector<int>>(sz+2, vector<int>(A,-1));
	rep(i,sz) rep(j,A) pt[i][j] = nd[i]->go[j]->id;
	
	auto get = [&](int a, int b){
	    if(b >= SZ) b = SZ-1;
	    return nd[a] -> sum[b];
	};
	rep(i,sz) dp[n][i] = get(i, 0);
	for(int i=n-1;i>=0;i--){
	    rep(j,sz){
	        //calc dp[i][j] from dp[i+1][*]
	        int add = get(j, n-i);
	        rep(nxt, A){
	            chmax(dp[i][j], dp[i+1][pt[j][nxt]] + add);
	        }
	    }
	}
	string ans = "";
	int best = dp[0][0];
	int cur = 0;
	for(int i=0;i<n;i++){
	    //dp[i][cur]
	    int mn = -INF;
	    rep(nxt, A){
	        chmax(mn, dp[i+1][pt[cur][nxt]]);
	    }
	    rep(nxt, A){
	        if(mn == dp[i+1][pt[cur][nxt]]){
	            ans.pb('0'+nxt);
	            best -= get(cur, n-i);
	            cur = pt[cur][nxt];
	            break;
	        }
	    }
	}
	cout << dp[0][0] << endl << ans << endl;
}