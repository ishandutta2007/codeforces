#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
bool ispref(string u,string v,int x,int y){
	if(u.size()>v.size()) return 0;
	int num=(x>y);
	bool ok=true;
	for(int i=1; i<=u.size() ;i++){
		if(v[v.size()-i]!=u[u.size()-i]) ok=false;
	}
	if(ok) num++;
	if(u.size()<v.size() && ok) num++;
	return (num>=2);
}
string a[21];
bool out[21];
unordered_map<string,vector<pair<string,bool> > >um;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		out[i]=um[a[i]].empty();
		cnt+=out[i];
		int t;
		cin >> t;
		for(int j=1; j<=t ;j++){
			string tmp;
			cin >> tmp;
			um[a[i]].push_back(make_pair(tmp,1));
		}
	}
	cout << cnt << endl;
	for(int i=1; i<=n ;i++){
		if(!out[i]) continue;
		cout << a[i];
		int num=um[a[i]].size();
		int cnt2=0;
		for(int j=0; j<num ;j++){
			for(int k=0; k<num ;k++){
				if(ispref(um[a[i]][j].first,um[a[i]][k].first,j,k)) um[a[i]][j].second=false;
			}
			cnt2+=um[a[i]][j].second;
		}
		cout << ' ' << cnt2;
		for(int j=0; j<num ;j++){
			if(um[a[i]][j].second) cout << ' ' << um[a[i]][j].first;
		}
		cout << endl;
	}
}