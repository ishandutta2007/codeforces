#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,3> cool;
#define fi first
#define se second
int n;
vector<pair<cool,int> >v;
vector<pair<cool,int> >u;
vector<pair<cool,int> >w;
void dumb(int p,int q){
	for(int i=p; i<=q ;i+=2){
		if(i==q) w.push_back(v[i]);
		else cout << v[i].se << ' ' << v[i+1].se << '\n';
	}
}
void solve(int p,int q){
	//cout << "s " << p << ' ' << q << endl;
	for(int i=p; i<=q ;i++){
		int l=i,r=i;
		while(r<=q && v[r].fi[1]==v[l].fi[1]) r++;
		i=r-1;
		dumb(l,r-1);
	}
	for(int i=0; i<w.size() ;i+=2){
		if(i==w.size()-1) u.push_back(w[i]);
		else cout << w[i].se << ' ' << w[i+1].se << '\n';
	}
	w.clear();
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x,y,z;cin >> x >> y >> z;
		cool w={x,y,z};
		v.push_back({w,i});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size() ;i++){
		int l=i,r=i;
		while(r<v.size() && v[r].fi[0]==v[l].fi[0]) r++;
		i=r-1;
		solve(l,r-1);
	}
	for(int i=0; i<u.size() ;i+=2){
		cout << u[i].se << ' ' << u[i+1].se << '\n';
	}
}