#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 500*1000+10;
int t,n,m;
int hsh[nax];
pair<ll,ll> sum[nax];
vi V[nax];

int rand(int a,int b) {
	return a + (rand()%(b-a+1));
}

int main() {_
	srand(time(NULL));
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			V[i].clear();
			cin>>sum[i].ND;
		}
		for(int a,b,i=1; i<=m; i++) {
			cin>>a>>b;
			V[b].PB(a);
		}
		for(int i=1; i<=n; i++) {
			hsh[i] = rand(1,1000*1000*1000);
		}
		for(int i=1; i<=n; i++) {
			sum[i].ST = 0;
			for(auto it:V[i]) sum[i].ST+=hsh[it];
		}
		sort(sum+1,sum+n+1);
		int wsk = 1;
		while(wsk<=n&&sum[wsk].ST==0) wsk++;
		ll s = sum[wsk].ND, ans = 0;
		for(int i=wsk+1; i<=n; i++) {
			if(sum[i].ST!=sum[i-1].ST) {
				ans = __gcd(ans,s);
				s=0;
			}
			s+=sum[i].ND;
		}
		ans = __gcd(ans,s);
		cout<<ans<<"\n";
	}
		
}