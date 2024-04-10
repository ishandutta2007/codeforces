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

#define SORT(x) sort(x.begin(), x.end())
#define POSL(x, v) lower_bound(x.begin(),x.end(),v)-x.begin()

string s;
int cr[105];
vc<string>parallel(vc<vc<string>>dat){
	int n = 0, m = 0;
	rep(i, dat.size()){
		n += dat[i].size();
		chmax(m, (int)dat[i][0].size());
	}
	m += 6;
	n += dat.size()-1;
	
	vc<string>ret(n);
	rep(i, n) rep(j, m) ret[i].pb(' ');
	
	ret[1][0] = ret[1][m-1] = '+';
	ret[1][1] = '-';
	ret[1][2] = '>';
	ret[1][m-2] = '>';
	int z = 1;
	rep(i, dat.size()-1){
		for(int j=z+1;j<z+dat[i].size()+1;j++){
			ret[j][0] = ret[j][m-1] = '|';
		}
		z += dat[i].size()+1;
		ret[z][0] = ret[z][m-1] = '+';
		ret[z][1] = '-';
		ret[z][2] = '>';
		ret[z][m-2] = '>';
	}
	z = 0;
	rep(i, dat.size()){
		rep(x, dat[i].size()) rep(y, dat[i][0].size()){
			ret[x+z][y+3] = dat[i][x][y];
		}
		int p = dat[i][0].size()+3;
		while(p < m-2){
			ret[z+1][p] = '-';
			p++;
		}
		z += dat[i].size()+1;
	}
	return ret;
}
vc<string>Line(vc<vc<string>>dat){
	int n = 0, m = 0;
	rep(i, dat.size()){
		chmax(n, (int)dat[i].size());
		m += dat[i][0].size();
	}
	m += 2*(dat.size()-1);
	vc<string>ret(n);
	rep(i, n) rep(j, m) ret[i].pb(' ');
	
	int z = 0;
	rep(i, dat.size()){
		rep(x, dat[i].size()) rep(y, dat[i][0].size()){
			ret[x][y+z] = dat[i][x][y];
		}
		if(i+1 == dat.size()) break;
		ret[1][z+dat[i][0].size()] = '-';
		ret[1][z+dat[i][0].size()+1] = '>';
		z += dat[i][0].size()+2;
	}
	
	return ret;
}
vc<string>expr(int l, int r);
vc<string>term(int l, int r);
vc<string>to_box(string s);
vc<string>sp(vc<string>v, string c);

vc<string>expr(int l, int r){
	vc<vc<string>>dat;
	int las = l-1;
	int dep = 0;
	for(int i=l;i<=r;i++){
		if(s[i] == '|' && dep == 0){
			dat.pb(term(las+1, i-1));
			las = i;
		}
		else if(s[i] == '(') dep ++;
		else if(s[i] == ')') dep --;
	}
	dat.pb(term(las+1, r));
	
	if(dat.size() == 1) return dat[0];
	else return parallel(dat);
}
vc<string>term(int l, int r){
	vc<vc<string>>dat;
	while(l <= r){
		if(s[r] == ')'){
			dat.pb(expr(cr[r]+1, r-1));
			r = cr[r]-1;
		}
		else if('A' <= s[r] && s[r] <= 'Z'){
			string x = "";
			int pt = r;
			while(pt >= l && 'A' <= s[pt] && s[pt] <= 'Z'){
				x.pb(s[pt]);
				pt --;
			}
			reverse(x.begin(), x.end());
			dat.pb(to_box(x));
			r = pt;
		}
		else{
			string x = "";
			int pt = r;
			while(pt >= l && (s[pt] == '+' || s[pt] == '?' || s[pt] == '*')){
				x.pb(s[pt]);
				pt --;
			}
			vc<string>dd;
			if(s[pt] == ')'){
				dd = expr(cr[pt]+1, pt-1);
				pt = cr[pt]-1;
			}
			else{
				string sss = ""; sss.pb(s[pt]);
				dd = to_box(sss);
				pt --;
			}
			reverse(x.begin(), x.end());
			dat.pb(sp(dd, x));
			r = pt;
		}
	}
	reverse(dat.begin(), dat.end());
	if(dat.size() == 1) return dat[0];
	else return Line(dat);
}
vc<string>to_box(string s){
	int n = 3, m = 4 + s.size();
	vc<string>ret(n);
	rep(i, n) rep(j, m) ret[i].pb((i==1?' ':'-'));
	rep(j, s.size()) ret[1][j+2] = s[j];
	rep(i, 3) ret[i][0] = ret[i][m-1] = '+';
	return ret;
}
vc<string>sp(vc<string>v, string c){
	if(c.empty()) return v;
	int n = v.size(), m = v[0].size();
	if(c[0] == '+'){
		vc<string>vv(n+2);
		rep(i,n+2)rep(j,m+6) vv[i].pb(' ');
		vv[1][0] = '+'; vv[1][1] = '-'; vv[1][2] = '>';
		vv[1][m+3] = '-', vv[1][m+4] = '>', vv[1][m+5] = '+';
		
		for(int i=2;i<=n;i++){
			vv[i][0] = vv[i][m+5] = '|';
		}
		vv[n+1][0] = vv[n+1][m+5] = '+';
		vv[n+1][1] = '<';
		for(int i=2;i<m+5;i++) vv[n+1][i] = '-';
		
		rep(i, n) rep(j, m) vv[i][j+3] = v[i][j];
		return sp(vv, c.substr(1));
	}
	else if(c[0] == '?'){
		vc<string>vv(n+3);
		rep(i,n+3)rep(j,m+6) vv[i].pb(' ');
		vv[1][0] = '+'; vv[1][m+5] = '+'; vv[1][m+4] = '>';
		for(int i=1;i<m+4;i++) vv[1][i] = '-';
		
		for(int i=2;i<4;i++){
			vv[i][0] = vv[i][m+5] = '|';
		}
		vv[4][0] = vv[4][m+5] = '+';
		vv[4][1] = vv[4][m+3] = '-';
		vv[4][2] = vv[4][m+4] = '>';
		rep(i,n)rep(j,m){
			vv[3+i][j+3] = v[i][j];
		}
		return sp(vv, c.substr(1));
	}
	else{
		vc<string>vv(n+5);
		rep(i,n+5)rep(j,m+6) vv[i].pb(' ');
		vv[1][0] = '+'; vv[1][m+5] = '+'; vv[1][m+4] = '>';
		for(int i=1;i<m+4;i++) vv[1][i] = '-';
		
		for(int i=2;i<4;i++){
			vv[i][0] = vv[i][m+5] = '|';
		}
		vv[4][0] = vv[4][m+5] = '+';
		vv[4][1] = vv[4][m+3] = '-';
		vv[4][2] = vv[4][m+4] = '>';
		rep(i,n)rep(j,m){
			vv[3+i][j+3] = v[i][j];
		}
		for(int i=5;i<=n+3;i++){
			vv[i][0] = vv[i][m+5] = '|';
		}
		vv[n+4][0] = vv[n+4][m+5] = '+';
		vv[n+4][1] = '<';
		for(int i=2;i<m+5;i++) vv[n+4][i] = '-';
		return sp(vv, c.substr(1));
	}
}
void solve(){
	cin >> s;
	stack<int>S;
	rep(i, s.size()){
		if(s[i] == '(') S.push(i);
		else if(s[i] == ')'){
			cr[S.top()] = i;
			cr[i] = S.top();
			S.pop();
		}
	}
	auto ans = expr(0, s.size()-1);
	vc<string>R(ans.size());
	rep(i, ans.size()) rep(j, ans[0].size()+6) R[i].pb(' ');
	
	cout << ans.size() << " " << ans[0].size()+6 << endl;
	rep(i, ans.size()){
		rep(j, ans[0].size()) R[i][j+3] = ans[i][j];
	}
	R[1][0] = 'S', R[1][1] = '-', R[1][2] = '>';
	R[1][ans[0].size()+3] = '-', R[1][ans[0].size()+4] = '>', R[1][ans[0].size()+5] = 'F';
	
	rep(i,ans.size()){
		cout<<R[i]<<endl;
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}