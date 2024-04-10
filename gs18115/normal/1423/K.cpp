#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000000;

int N;
vector<pii> v;
int ans[MAX_N+1];
bool chk[MAX_N+1];

deque<int> dq;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		v.pb({x, i});
	}
	int now = 1;
	int x = 1;
	sort(v.begin(), v.end());
	int idx = 0;
	while(x<=MAX_N){
		//cout<<x<<" "<<now<<endl;
		while(idx<(int)v.size() && v[idx].first==x){
			ans[v[idx].second] = now;
			idx++;
		}
		x++;
		if(x>MAX_N)	break;
		if(!chk[x])	now++;
		if(!chk[x] && x<=(MAX_N/x)){
			//TEST cout<<x<<endl;
			for(int j=x*x; j<=MAX_N; j+=x){
				chk[j] = true;
			}
			dq.pb(x);
		}
		if(!dq.empty()){
			int t = dq.front();
			if(t<=(MAX_N/t) && t*t==x){
				now--;
				dq.pop_front();
			}
		}
	}
	sort(v.begin(), v.end());

	for(int i=1; i<=N; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}