#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
int n,m;
int a[500001];

int f[500001];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		if(c=='R') a[i]=1;
		else a[i]=0;
	}
	int nim=0;
	int al=0,bb=0;
	for(int i=1; i<=n ;i++){
		int r=i;
		while(r<n && a[r+1]!=a[r]) r++;
		
		int len=r-i+1;
		i=r;
		nim^=f[len];
	}
	if(nim) al++;
	for(int i=1; i<=n ;i++){
		if(a[i]==1) al++;
		else al--;
	}
	if(al>bb) cout << "Alice\n";
	else cout << "Bob\n";
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	{
		for(int i=2; i<=500000 ;i++){
			if(i>100){
				f[i]=f[i-34];
				continue;
			}
			set<int>s;
			for(int j=0; j<=i-2 ;j++){
				s.insert(f[j]^f[i-j-2]);
			}
			while(true){
				auto it=s.lower_bound(f[i]);
				if(it!=s.end() && *it==f[i]) f[i]++;
				else break;
			}
		}
	}
	int t;cin >> t;while(t--) solve();
}