#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=17;
ll n,k;
ll a[N],b[N];
bitset<2001>dp[65536];
bitset<2001>dp2[65536];
int c[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	for(int i=0; i<n ;i++){
		cin >> a[i];
	}
	dp[0][0]=1;
	for(int i=1; i<(1<<n) ;i++){
		for(int j=0; j<n ;j++){
			if((i&(1<<j))==0) continue;
			dp2[i]|=dp[i^(1<<j)]<<a[j];
		}
		for(int j=2000; j>=0 ;j--){
			if(dp2[i][j]) dp[i][j]=1;
			if(j*k<=2000 && dp[i][j*k]) dp[i][j]=1;
		}
	}
	int mg=(1<<n)-1;
	int x=1;
	int sin=0;
	if(!dp[mg][1]) return cout << "NO\n",0;
	cout << "YES\n";
	while(mg!=0){
		if(x*k<=2000 && dp[mg][x*k]){
			sin++;x*=k;continue;
		}
		for(int j=0; j<n ;j++){
			if((mg&(1<<j))==0) continue;
			if(x>=a[j] && dp[mg^(1<<j)][x-a[j]]){
				c[j]=sin;
				mg^=(1<<j);
				x-=a[j];
			}
		}
	}
	
	priority_queue<pii >pq;
	for(int i=0; i<n ;i++){
		pq.push({c[i],a[i]});
	}
	while(pq.size()>1){
		auto x=pq.top();pq.pop();
		auto y=pq.top();pq.pop();
		int w=x.fi;
		cout << x.se << ' ' << y.se << '\n';
		int z=x.se+y.se;
		while(z%k==0){
			z/=k;
			w--;
		}
		pq.push({w,z});
	}
}