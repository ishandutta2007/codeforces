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

long long fen[100005]; //initialize to 0, this is 1-indexed
void update(int i,long long j){ //adds j to ith term
    while (i<100005){
        fen[i]+=j;
        i+=(i&(-i));
    }
}
long long query(int i){ //calculate the sum of the 1-i terms
    long long k=0;
    while (i>0){
        k+=fen[i];
        i-=(i&(-i));
    }
    return k;
}

int n;
int arr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) arr[x]+=arr[x-1];
	
	vector<int> idx;
	rep(x,1,n+1) idx.pub(x);
	
	sort(all(idx),[](int i,int j){
		if (arr[i]!=arr[j]) return arr[i]<arr[j];
		else return i<j;
	});
	
	//for (auto it:idx) cout<<it<<" "; cout<<endl;
	
	if (arr[idx[0]]<0 || idx[n-1]!=n){
		cout<<"-1"<<endl;
		return 0;
	}
	
	reverse(all(idx));
	int ans=0;
	for (auto it:idx){
		ans+=query(it);
		update(it,1);
	}
	
	cout<<ans<<endl;
}