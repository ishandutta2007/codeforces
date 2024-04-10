#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll la[250001],ra[250001];
ll lb[250001],rb[250001];
multiset<ll>sl,sr;
pair<ll,pair<int,int> >st[500001];
bool solve(){
	for(int i=1; i<=n ;i++){
		st[i*2-1]={la[i],{i,1}};
		st[i*2]={ra[i]+1,{i,-1}};
	}
	sl.clear();
	sr.clear();
	sort(st+1,st+2*n+1);
	for(int i=1; i<=2*n ;i++){
		//cout << "doing " << i << endl;
		int id=st[i].se.fi;
		//cout << st[i].fi << ' ' << st[i].se.fi << ' ' << st[i].se.se << endl;
		if(st[i].se.se==-1){
			sl.erase(sl.find(lb[id]));
			sr.erase(sr.find(rb[id]));
		}
		else{
			sl.insert(lb[id]);
			sr.insert(rb[id]);
		}
		if(i==2*n || st[i].fi!=st[i+1].fi){
			if(sl.empty()) continue;
			auto it1=sl.end();--it1;
			auto it2=sr.begin();
			if(*it2<*it1) return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> la[i] >> ra[i] >> lb[i] >> rb[i];
	}
	if(!solve()) return cout << "NO\n",0;
	for(int i=1; i<=n ;i++){
		swap(la[i],lb[i]);
		swap(ra[i],rb[i]);
	}
	if(!solve()) return cout << "NO\n",0;
	cout << "YES\n";
}