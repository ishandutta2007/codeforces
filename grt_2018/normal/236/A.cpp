#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int ans;
string s;
bool used[26];

int main() {_
	cin>>s;
	for(auto it:s) {
		used[it-'a']=1;
	}
	for(int i=0; i<26;i++) ans+=used[i];
	if(ans&1) cout<<"IGNORE HIM!";
	else cout<<"CHAT WITH HER!";		
}