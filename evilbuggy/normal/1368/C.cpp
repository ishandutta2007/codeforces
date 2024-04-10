#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	if(n&1){
		set<pair<int, int> > vec;
		for(int i = 0; i <= 2*n; i++){
			vec.insert({i, 0});
		}
		for(int i = 1; i < 2*n; i += 2){
			vec.insert({i, 1});
			vec.insert({i, -1});
		}
		for(int i = 1; i < 2*n; i += 4){
			vec.insert({i, 2});
			vec.insert({i + 1, 2});
			vec.insert({i + 2, 2});
		}
		for(int i = 3; i < 2*n; i += 4){
			vec.insert({i, -2});
			vec.insert({i + 1, -2});
			vec.insert({i + 2, -2});
		}
		vec.insert({2*n - 1, 2});
		vec.insert({2*n, 2});
		vec.insert({2*n + 1, 2});
		vec.insert({2*n + 1, 1});
		vec.insert({2*n + 1, 0});

		vec.insert({-1, 0});
		vec.insert({-1, -1});
		vec.insert({-1, -2});
		vec.insert({0, -2});
		vec.insert({1, -2});
		cout<<vec.size()<<'\n';
		for(auto pp : vec){
			cout<<pp.first<<" "<<pp.second<<'\n';
		}
	}else{
		set<pair<int, int> > vec;
		for(int i = 0; i <= 2*n; i++){
			vec.insert({i, 0});
		}
		for(int i = 1; i < 2*n; i += 2){
			vec.insert({i, 1});
			vec.insert({i, -1});
			vec.insert({i, 2});
			vec.insert({i, -2});
		}
		for(int i = 2; i < 2*n; i += 4){
			vec.insert({i, 2});
			vec.insert({i, -2});
		}
		for(int i = 0; i <= 10; i++){
			vec.insert({-1, i});
			vec.insert({2*n + 1, i});
		}
		for(int i = 0; i <= 2*n; i++){
			vec.insert({i, 10});
		}
		cout<<vec.size()<<'\n';
		for(auto pp : vec){
			cout<<pp.first<<" "<<pp.second<<'\n';
		}
	}

	return 0;
}