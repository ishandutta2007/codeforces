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


int d[1000000], s[1000000];

int main(){
	int n;
	scanf("%d", &n);
	queue<int> q;
	rep(i,0,n){
		scanf("%d%d", d+i, s+i);
		if(d[i] == 1){
			q.push(i);
		}
	}
	vector<pair<int, int> > ans;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(!d[cur])
			continue;
		int to=s[cur];
		--d[to];
		s[to]^=cur;
		if(d[to] == 1)
			q.push(to);
		ans.push_back({cur, to});
	}
	printf("%d\n", ans.size());
	rep(i,0,ans.size()){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}