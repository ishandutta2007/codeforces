#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int a,b,c,d,e,f;
int x,y;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>a>>b>>c>>d>>e>>f;
		cin>>x>>y;
		
		int X,Y;
		
		map<int,int> occ;
		occ[a]++,occ[c]++,occ[e]++;
		
		for (auto [a,b]:occ) if (b==2) X=a;
		
		occ.clear();
		occ[b]++,occ[d]++,occ[f]++;
		
		for (auto [a,b]:occ) if (b==2) Y=a;
		
		//cout<<X<<" "<<Y<<endl;
		if ((X==1 || X==n) && (Y==1 || Y==n)){
			if (x==X || y==Y) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			if (x%2==X%2 || y%2==Y%2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}