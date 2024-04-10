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

int n, m;
set<int> used;
vector<int> order;
int w[1005];
int b[1005];
stack<int> S;
stack<int> Q;

int main(){
	cin >> n >> m;
	rep(i, 0, n)
		cin >> w[i];
	rep(i, 0, m){
		cin >> b[i];
		--b[i];
		if(used.find(b[i]) == used.end()){
			order.push_back(b[i]);
			used.insert(b[i]);
		}
	}
	for(int i=order.size()-1; i >= 0; --i)
		S.push(order[i]);
	long long ans=0;
	rep(i, 0, m){
		while(S.top() != b[i]){
			ans += w[S.top()];
			Q.push(S.top());
			S.pop();
		}
		S.pop();
		while(!Q.empty()){
			S.push(Q.top());
			Q.pop();
		}
		S.push(b[i]);
	}
	cout << ans << endl;
}