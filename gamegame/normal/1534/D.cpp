#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
int d[N];
vector<int>v1,v2;
set<pair<int,int> >s;
void go(int id){
	cout << "? " << id << endl;
	for(int i=1; i<=n ;i++){
		cin >> d[i];
		if(d[i]==1){
			s.insert({min(id,i),max(id,i)});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;go(1);
	for(int i=2; i<=n ;i++){
		if(d[i]%2==1) v1.push_back(i);
		else v2.push_back(i);
	}
	if(v1.size()>v2.size()) swap(v1,v2);
	for(auto c:v1){
		go(c);
	}
	cout << "!" << endl;
	for(auto c:s) cout << c.fi << ' ' << c.se << endl;
}