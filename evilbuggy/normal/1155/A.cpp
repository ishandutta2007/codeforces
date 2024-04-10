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
	string s;
	cin>>n>>s;
	char ch = s[0];
	bool impos = true;
	for(auto x : s){
		if(x < ch){
			impos = false;
			break;
		}
		ch = x;
	}
	if(impos){
		cout<<"NO"<<endl;
		return 0;
	}
	int f[26];
	memset(f, -1, sizeof(f));
	for(int i = 0; i < n; i++){
		f[s[i] - 'a'] = i;
	}
	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++){
		int c = s[i] - 'a';
		for(int j = 0; j < c; j++){
			if(i < f[j]){
				cout<<i+1<<" "<<f[j] + 1<<endl;
				return 0;
			}
		}
	}

	return 0;
}