#include<bits/stdc++.h>
using namespace std;
typedef double dd;
vector<double>v;
int n;
dd x[1001],y[1001];
dd m(int u,int v){
	if(x[u]==x[v]) return 1e18;
	return (y[v]-y[u])/(x[v]-x[u]);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n ;i++){
		cin >> x[i] >> y[i];
		for(int j=0; j<i ;j++){
			bool ok=true;
			for(int k=0; k<i ;k++){
				if(j==k) continue;
				if(m(i,j)==m(i,k)) ok=false;
			}
			if(ok) v.push_back(m(i,j));
		}
	}
	sort(v.begin(),v.end());
	int ans=v.size()*(v.size()-1)/2;
	int eq=0;
	for(int i=0; i<v.size() ;i++){
		if(i!=0 && abs(v[i]-v[i-1])>1e-9) eq=0;
		ans-=eq;
		eq++;
	}
	cout << ans << endl;
}