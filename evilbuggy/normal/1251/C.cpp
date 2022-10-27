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

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int> ev, od;
		for(auto ch : s){
			int v = ch - '0';
			if(v&1)od.push_back(v);
			else ev.push_back(v);
		}
		int i = 0, j = 0;
		while(i < od.size() && j < ev.size()){
			if(od[i] < ev[j]){
				cout<<od[i];
				i++;
			}else{
				cout<<ev[j];
				j++;
			}
		}
		while(i < od.size()){
			cout<<od[i];
			i++;
		}
		while(j < ev.size()){
			cout<<ev[j];
			j++;
		}
		cout<<'\n';
	}

	return 0;
}