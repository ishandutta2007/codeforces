//Author: Heltion
//Date: 2019-06-05
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
template<typename T>void no(const T&x){cout<<x;exit(0);}
template<typename T=int>auto read(){T x;cin>>x;return x;}
template<typename T>void maxi(T&x,const T&y){if(y>x)x=y;}
template<typename T>void mini(T&x,const T&y){if(y<x)x=y;}
template<typename T>void sort(vector<T>&v){sort(v.begin(),v.end());}
template<typename T>void subm(T&x,const T&y,const T&m=mod){x-=y;if(x<0)x+=m;}
template<typename T>void addm(T&x,const T&y,const T&m=mod){x+=y;if(x>=m)x-=m;}
template<typename T=int>auto input(int n){vector<T>v(n);for(auto&x:v)cin>>x;return v;}
LL power(LL x,LL r,LL m=mod){LL res=1;for(;r;r>>=1,x=x*x%mod)if(r&1)res=res*x%mod;return res;}
template<typename F,typename R>auto&operator>>(istream&is,pair<F,R>&p){return is>>p.first>>p.second;}
template<typename T>auto&operator<<(ostream&os,const vector<T>&v){for(const auto&x:v)os<<x<<" ";return os;}
template<typename F,typename R>auto&operator<<(ostream&os,const pair<F,R>&p){return os<<p.first<<" "<<p.second;}
constexpr int maxn = 320000;
vector<int> v[maxn];
int a[maxn], ans = 0;
set<int> s;
void solve(int p, int L, int R, int l, int r){
	//cerr << p << " " << L << " " << R << " " << l << " " << r << "\n";
	if(*s.rbegin() == p) ans += 1;
	if(s.count(p + 1)) solve(p + 1, L, R, l, r);
	else{
		int nxt = *lower_bound(v[p + 1].begin(), v[p + 1].end(), r);
		int pre = *(upper_bound(v[p + 1].begin(), v[p + 1].end(), l) - 1);
		//cerr << pre << " " << nxt << "\n";
		if(nxt <= R){
			int ok = true, j;
			for(j = r + 1; j <= nxt; j += 1)
				if(s.count(a[j])){
					ok = false;
					break;
				}
				else s.insert(a[j]);
			if(not ok) for(j -= 1; j > r; j -= 1) s.erase(a[j]);
			else{
				j -= 1;
				solve(p + 1, max(L, pre + 1), R, l, j);
				for(; j > r; j -= 1) s.erase(a[j]);
			}
		}
		if(pre >= L){
			int ok = true, j;
			for(j = l - 1; j >= pre; j -= 1)
				if(s.count(a[j])){
					ok = false;
					break;
				}
				else s.insert(a[j]);
			if(not ok) for(j += 1; j < l; j += 1) s.erase(a[j]);
			else{
				j += 1;
				solve(p + 1, L, min(R, nxt - 1), j, r);
				for(; j < l; j += 1) s.erase(a[j]);
			}
		}
	}
}
int _main(){
	int n = read();
	for(int i = 1; i <= n + 1; i += 1) v[i].push_back(0);
	for(int i = 1; i <= n; i += 1)
		v[a[i] = read()].push_back(i);
	for(int i = 1; i <= n + 1; i += 1) v[i].push_back(n + 1);
	s.insert(1);
	for(int i = 1; i < (int)v[1].size() - 1; i += 1)
		solve(1, v[1][i - 1] + 1, v[1][i + 1] - 1, v[1][i], v[1][i]);
	cout << ans;
	return 0;
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);cout<<fixed<<setprecision(12);return _main();}