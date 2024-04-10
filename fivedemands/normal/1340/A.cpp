#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
int n,m;
int a[N];
int p[N];
multiset<int>s,t;
void solve(){
	cin >> n;s.clear();t.clear();
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		p[x]=i;
		s.insert(i);
		t.insert(1);
	}
	for(int i=1; i<=n ;i++){
		auto it=s.find(p[i]);
		int x=0;
		if(it!=s.begin()){
			auto it2=it;
			--it2;x=*it2;
		}
		auto it3=t.end();--it3;
		if(*it3!=p[i]-x){
			cout << "No\n";
			return;
		}
		t.erase(it3);
		auto it4=it;
		++it4;
		if(it4==s.end()){
			s.erase(it);
			continue;
		}
		t.erase(t.find(*it4-p[i]));
		t.insert(*it4-x);
		s.erase(it);
	}
	cout << "Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}