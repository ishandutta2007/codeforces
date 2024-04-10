#include<iostream>
#include<map>
using namespace std;
#define fi first
#define se second
int n;
string s[100001];
map<int,int>m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> s[i];
		int cur=0;
		int mini=0;
		for(int j=0; j<s[i].size() ;j++){
			if(s[i][j]==')') cur--;
			else cur++;
			mini=min(mini,cur);
		}
		if(cur>=0){
			if(mini==0) m[cur]++;
		}
		else{
			if(-cur+mini>=0) m[cur]++;
		}
	}
	int ans=0;
	for(auto cur:m){
		if(cur.fi>0) break;
		if(cur.fi==0) ans+=cur.se/2;
		else{
			ans+=min(cur.se,m[-cur.fi]);
		}
	}
	cout << ans << endl;
}