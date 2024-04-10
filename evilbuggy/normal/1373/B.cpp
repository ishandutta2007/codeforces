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
		int cnt[2] = {0, 0};
		for(auto ch : s){
			cnt[ch - '0']++;
		}
		if(min(cnt[0], cnt[1])%2 == 0){
			cout<<"NET"<<'\n';
		}else{
			cout<<"DA"<<'\n';
		}
	}

	return 0;
}