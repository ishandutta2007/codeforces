//Author: Heltion
//Date: 2019-06-05
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1000000007;
template<typename T>void no(const T&x){cout<<x;exit(0);}
template<typename T=int>auto read(){T x;cin>>x;return x;}
template<typename T>void maxi(T&x,const T&y){if(y>x)x=y;}
template<typename T>void mini(T&x,const T&y){if(y<x)x=y;}
template<typename T>void subm(T&x,const T&y){x-=y;if(x<0)x+=mod;}
template<typename T>void addm(T&x,const T&y){x+=y;if(x>=mod)x-=mod;}
template<typename T>void sort(vector<T>&v){sort(v.begin(),v.end());}
template<typename T=int>auto input(int n){vector<T>v(n);for(auto&x:v)cin>>x;return v;}
template<typename F,typename R>auto&operator>>(istream&is,pair<F,R>&p){return is>>p.first>>p.second;}
template<typename T>auto&operator<<(ostream&os,const vector<T>&v){for(const auto&x:v)os<<x<<" ";return os;}
template<typename F,typename R>auto&operator<<(ostream&os,const pair<F,R>&p){return os<<p.first<<" "<<p.second;}
constexpr int maxn = 0;

int _main(){
	auto v = input(read() * 2);
	sort(v);
	if(v[0] != v.back()) cout << v;
	else cout << -1;
	return 0;
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);cout<<fixed<<setprecision(12);return _main();}