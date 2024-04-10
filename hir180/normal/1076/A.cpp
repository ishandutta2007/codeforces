#include <bits/stdc++.h>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
string str;
int main(){
	cin>>n>>str;
	vector<pair<char,int> >vec;
	char ch = '1';
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(i == 0){
			ch = str[i];
			cnt = 1;
		}
		else if(ch != str[i]){
			vec.pb(mp(ch,cnt));
			ch = str[i];
			cnt = 1;
		}
		else cnt++;
	}
	vec.pb(mp(ch,cnt));
	for(int i=1;i<vec.size();i++){
		if(vec[i-1].fi > vec[i].fi){
			vec[i-1].sc--; goto nxt;
		}
	}
	vec[vec.size()-1].sc--;
	nxt:;
	string ans = "";
	rep(i,vec.size()){
		rep(j,vec[i].sc) ans.pb(vec[i].fi);
	}
	cout << ans << endl;
}