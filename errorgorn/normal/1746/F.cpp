//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

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

const int B=30;

struct FEN{
	int arr[300005];
	
	void update(int i,int j){
		while (i<300005){
			arr[i]+=j;
			i+=i&-i;
		}
	}
	
	int query(int i){
		int res=0;
		while (i){
			res+=arr[i];
			i-=i&-i;
		}
		return res;
	}
	
	int query(int i,int j){
		return query(j)-query(i-1);
	}
} fen[B];

int n,q;
int arr[300005];

int af=(1<<B)-1;
unordered_map<int,int> m;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) if (!m.count(arr[x])) m[arr[x]]=rng()&af;
	
	rep(x,1,n+1){
		int bm=m[arr[x]];
		rep(y,0,B) if (bm&(1<<y)) fen[y].update(x,1);
	}
	
	int a,b,c;
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a>>b;
			if (!m.count(b)) m[b]=rng()&af;
			int bm1=m[arr[a]],bm2=m[b];
			
			rep(y,0,B){
				int A=!!(bm1&(1<<y)),B=!!(bm2&(1<<y));
				if (A==1 && B==0) fen[y].update(a,-1);
				if (A==0 && B==1) fen[y].update(a,1);
			}
			
			arr[a]=b;
		}
		else{
			cin>>a>>b>>c;
			bool ok=true;
			rep(y,0,B) if (fen[y].query(a,b)%c) ok=false;
			
			if (ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
}