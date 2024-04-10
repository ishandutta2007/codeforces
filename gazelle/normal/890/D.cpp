#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<string> s(n);
	REP(i,n) cin>>s[i];
	REP(i,n) {
		vector<ll> c(26,0);
		REP(j,(ll)s[i].size()) {
			if(c[s[i][j]-'a']!=0) {
				cout<<"NO"<<endl;
				return 0;
			}
			c[s[i][j]-'a']++;
		}
	}
	vector<ll> e(26,-1);
	vector<ll> rev(26,-1);
	vector<bool> used(26,false);
	REP(i,n) {
		REP(j,(ll)s[i].size()) used[s[i][j]-'a']=true;
		FOR(j,1,(ll)s[i].size()) {
			if(e[s[i][j-1]-'a']!=-1&&e[s[i][j-1]-'a']!=(int)(s[i][j]-'a')) {
				cout<<"NO"<<endl;
				return 0;
			}
			if(rev[s[i][j]-'a']!=-1&&rev[s[i][j]-'a']!=(int)(s[i][j-1]-'a')) {
				cout<<"NO"<<endl;
				return 0;
			}
			e[s[i][j-1]-'a']=(int)(s[i][j]-'a');
			rev[s[i][j]-'a']=(int)(s[i][j-1]-'a');
		}
	}
	ll st=0,en=0;
	REP(i,26) {
		if(e[i]!=-1&&rev[i]==-1) st++;
		if(e[i]==-1&&rev[i]!=-1) en++;
	}
	if(st!=en) {
		cout<<"NO"<<endl;
		return 0;
	}
	vector<string> ss;
	REP(i,26) {
		if(used[i]) {
			string hoge="";
			hoge+='a'+i;
			if(e[i]==-1&&rev[i]==-1) ss.pb(hoge);
			else if(e[i]!=-1&&rev[i]==-1) {
				string ret="";
				ret+='a'+i;
				ll crt=i;
				while(1) {
					if(e[crt]==-1) break;
					crt=e[crt];
					ret+='a'+crt;
				}
				ss.pb(ret);
			}
		}
	}
	sort(ALL(ss));
	ll lgt=0;
	REP(i,(ll)ss.size()) {
		lgt+=(ll)ss[i].size();
	}
	ll usen=0;
	REP(i,26) if(used[i]) usen++;
	if(lgt!=usen) {
		cout<<"NO"<<endl;
		return 0;
	}
	REP(i,(ll)ss.size()) cout<<ss[i];
	cout<<endl;
}