#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int iu=1e6+1;
const int N=2e6+1;
int n,z;
int a[N];
int mn[N],mx[N];
int ans[N];
vector<int>f[N];
int mwah[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> z;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int s=0;
	for(int i=0; i<(1<<z) ;i++) ans[i]=1e9;
	while((1<<(s+1))<n) s++;
	for(int i=0; i<(1<<(z-s)) ;i++){
		for(int j=0; j<(1<<s) ;j++){
			f[j].clear();
		}
		for(int j=1; j<=n ;j++){
			int cur=(a[j]^i);
			f[cur>>(z-s)].push_back(cur%(1<<(z-s)));
		}/*
		cout << "doing " << i << endl;
		for(int u=0; u<2 ;u++){
			cout << u << ": ";
			for(auto c:f[u]) cout << c << ' ';
			cout << endl;
		}*/
		int funny=1e9;
		for(int j=0; j<(1<<s) ;j++){
			sort(f[j].begin(),f[j].end());
			for(int k=1; k<f[j].size() ;k++){
				funny=min(funny,f[j][k]-f[j][k-1]);
			}
		}
		for(int k=0; k<(1<<s) ;k++){
			int cur=(k<<(z-s))+i;
			ans[cur]=min(ans[cur],funny);
		}
		for(int j=0; j<s ;j++){
			for(int k=0; k<(1<<s) ;k++){
				mwah[k]=1e9;
			}
			for(int k=0; k<(1<<s) ;k++){
				int x1=k;
				int x2=k^((1<<(j+1))-1);
				if(f[x1].empty() || f[x2].empty()) continue;
				int bad=(((1<<j)-1)^k)%(1<<(j+1));
				mwah[bad]=min(mwah[bad],f[x2][0]-f[x1].back()+(1<<(z-s)));
			}
			for(int k=0; k<(1<<s) ;k++){
				int cur=(k<<(z-s))+i;
				ans[cur]=min(ans[cur],mwah[k%(1<<(j+1))]);
			}
		}
	}
	for(int i=0; i<(1<<z) ;i++) cout << ans[i] << ' ';
	cout << '\n';
}