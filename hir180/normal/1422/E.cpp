//Let's join Kaede Takagaki Fan Club !!
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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
vector<pair<char, int>>info;
deque<pair<char, int>>zan;
int sum_len;
vector<pair<int, string>>ans;
string str;

string get_str(char ch, int pat){
	if(sum_len+pat <= 10){
		string str = "";
		rep(i, pat) str.pb(ch);
		rep(i, zan.size()) rep(j, zan[i].sc) str.pb(zan[i].fi);
		return str;
	}
	else{
		string str = "";
		rep(i, pat) {
			if(str.size() >= 5) break;
			str.pb(ch);
		}
		rep(i, zan.size()){
			if(str.size() >= 5) break;
			rep(j, zan[i].sc){
				if(str.size() >= 5) break;
				str.pb(zan[i].fi);
			}
		}
		string str2 = "";
		int sz = zan.size();
		for(int i=sz-1;i>=0;i--){
			if(str2.size() >= 2) break;
			rep(j, zan[i].sc){
				if(str2.size() >= 2) break;
				str2.pb(zan[i].fi);
			}
		}
		rep(i, pat){
			if(str2.size() >= 2) break;
			str2.pb(ch);
		}
		reverse(str2.begin(), str2.end());
		str = str + "..." + str2;
		return str;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> str;
	int cnt = 0;
	char cur = 'A';
	for(const auto at:str){
		if(cur != at){
			if(cnt) info.pb(mp(cur, cnt));
			cur = at, cnt = 1;
		}
		else cnt++;
	}
	if(cnt) info.pb(mp(cur, cnt));
	
	for(int i=info.size()-1;i>=0;i--){
		bool big = 1;
		for(int j=0;j<zan.size();j++){
			if(zan[j].fi < info[i].fi) break;
			if(zan[j].fi > info[i].fi) { big = 0; break; }
		}
		for(int add=1;add<=info[i].sc;add++){
			int len;
			if(big) len = add%2; else len = add;
			ans.pb(mp(sum_len + len, get_str(info[i].fi, len)));
			if(add == info[i].sc){
				if(len){
					if(zan.empty() || zan[0].fi != info[i].fi){
						zan.push_front(mp(info[i].fi, len));
					}
					else{
						zan[0].sc += len;
					}
				}
				sum_len += len;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	rep(i, ans.size()){
		cout << ans[i].fi << " " << ans[i].sc << '\n';
	}
	return 0;
}