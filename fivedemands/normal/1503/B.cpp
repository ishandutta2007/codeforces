#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const ll N=2e6+1;
int n;
vector<pair<int,int> >p,q;
void kill(vector<pair<int,int> >& r,int s){
	cout << s << ' ' << r.back().fi << ' ' << r.back().se << endl;
	r.pop_back();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if((i+j)%2==0) p.push_back({i,j});
			else q.push_back({i,j});
		}
	}
	for(int i=1; i<=n*n ;i++){
		int a;cin >> a;
		if(a==1){
			if(q.empty()) kill(p,3);
			else kill(q,2);
		}
		else if(a==2){
			if(p.empty()) kill(q,3);
			else kill(p,1);
		}
		else{
			if(p.empty()) kill(q,2);
			else kill(p,1);
		}
	}
}