#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<vector<ll>> p(4);
vector<pair<ll,P>> act;
ll n,k,cnt;

void output() {
	cout<<act.size()<<endl;
	REP(i,(ll)act.size()) cout<<act[i].first<<" "<<act[i].second.first+1
	<<" "<<act[i].second.second+1<<endl;
	return;
}

void mv(P pos, char dir) {
	if(dir=='L') {
		act.pb(make_pair(p[pos.first][pos.second],P(pos.first,pos.second-1)));
		swap(p[pos.first][pos.second],p[pos.first][pos.second-1]);
	}
	if(dir=='R') {
		act.pb(make_pair(p[pos.first][pos.second],P(pos.first,pos.second+1)));
		swap(p[pos.first][pos.second],p[pos.first][pos.second+1]);
	}
	if(dir=='U') {
		act.pb(make_pair(p[pos.first][pos.second],P(pos.first-1,pos.second)));
		swap(p[pos.first][pos.second],p[pos.first-1][pos.second]);
		if(pos.first==1) p[pos.first][pos.second]=0;
	}
	if(dir=='D') {
		act.pb(make_pair(p[pos.first][pos.second],P(pos.first+1,pos.second)));
		swap(p[pos.first][pos.second],p[pos.first+1][pos.second]);
		if(pos.first==2) p[pos.first][pos.second]=0;
	}
	return;
}

void check() {
	REP(i,n) if(p[1][i]!=0&&p[1][i]==p[0][i]) {
		cnt++;
		mv(P(1,i),'U');
	}
	REP(i,n) if(p[2][i]!=0&&p[2][i]==p[3][i]) {
		cnt++;
		mv(P(2,i),'D');
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	REP(i,4) p[i].resize(n);
	REP(i,4) REP(j,n) cin>>p[i][j];
	bool d=false;
	FOR(i,1,3) REP(j,n) {
		if(d) continue;
		if(p[i][j]==0) d=true;
		else {
			if(i==1&&p[i-1][j]==p[i][j]) {
				cnt++;
				d=true;
				act.pb(make_pair(p[i][j],P(i-1,j)));
				p[i][j]=0;
				if(k==1) {
					output();
					return 0;
				}
			}
			if(i==2&&p[i+1][j]==p[i][j]) {
				cnt++;
				d=true;
				act.pb(make_pair(p[i][j],P(i+1,j)));
				p[i][j]=0;
				if(k==1) {
					output();
					return 0;
				}
			}
		}
	}
	if(!d) {
		cout<<-1<<endl;
		return 0;
	}
	P sp=P(-1,-1);
	FOR(i,1,3) REP(j,n) if(p[i][j]==0) sp=P(i,j);
	//cout<<sp.first<<" "<<sp.second<<endl;
	REP(c,2*n) {
		if(cnt==k) break;
		P pos=sp;
		REP(i,2*n-1) {
			if(pos.first==1) {
				if(pos.second==n-1) {
					if(p[pos.first+1][pos.second]) mv(P(pos.first+1,pos.second),'U');
					pos.first++;
				} else {
					if(p[pos.first][pos.second+1]) mv(P(pos.first,pos.second+1),'L');
					pos.second++;
				}
			} else {
				if(pos.second==0) {
					if(p[pos.first-1][pos.second]) mv(P(pos.first-1,pos.second),'D');
					pos.first--;
				} else {
					if(p[pos.first][pos.second-1]) mv(P(pos.first,pos.second-1),'R');
					pos.second--;
				}
			}
		}
		check();
		sp=pos;
	}
	output();
}