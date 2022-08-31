#include<iostream>
#include<map>
using namespace std;
int n;
map<int,int>m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		string s;
		cin >> s;
		int cur=0;
		for(int j=0; j<s.size() ;j++){
			cur^=(1<<(s[j]-'a'));
		}
		ans+=m[cur];
		for(int j=0; j<26 ;j++){
			ans+=m[cur^(1<<j)];
		}
		m[cur]++;
	}
	cout << ans << endl;
}