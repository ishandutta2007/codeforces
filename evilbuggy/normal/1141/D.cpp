#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<int> a[27], b[27];

int main(){
	int n;
	cin>>n;
	char ch;
	for(int i = 0; i < n; i++){
		cin>>ch;
		if(ch == '?')a[26].push_back(i);
		else a[ch - 'a'].push_back(i);
	}
	for(int i = 0; i < n; i++){
		cin>>ch;
		if(ch == '?')b[26].push_back(i);
		else b[ch - 'a'].push_back(i);
	}
	vector<int> aa, bb;
	vector<pair<int, int> > ans;
	for(int i = 0; i < 26; i++){
		int sz = min(a[i].size(), b[i].size());
		for(int j = 0; j < sz; j++){
			ans.emplace_back(a[i][j], b[i][j]);
		}
		for(int j = sz; j < a[i].size(); j++){
			aa.push_back(a[i][j]);
		}
		for(int j = sz; j < b[i].size(); j++){
			bb.push_back(b[i][j]);
		}
	}
	int sz1 = min(b[26].size(), aa.size());
	for(int i = 0; i < sz1; i++){
		ans.emplace_back(aa[i], b[26][i]);
	}
	int sz2 = min(a[26].size(), bb.size());
	for(int i = 0; i < sz2; i++){
		ans.emplace_back(a[26][i], bb[i]);
	}
	int sz = min(b[26].size() - sz1, a[26].size() - sz2);
	for(int i = 0; i < sz; i++){
		ans.emplace_back(a[26][i + sz2], b[26][i + sz1]);
	}
	cout<<ans.size()<<endl;
	for(auto x : ans){
		cout<<x.first + 1<<" "<<x.second + 1<<endl;
	}
}