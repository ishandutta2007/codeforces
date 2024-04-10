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

const int nax = 2000+10;
int t,n,k,m;
bool a[nax];
vector<pi> ans;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>k;
		m=0; ans={};
		for(int i=1; i<=n; i++) {
			char c;
			cin>>c;
			if(c=='(') a[i]=1;
			else a[i]=0;
		}
		int x = k;
		k=k*2;
		for(int i=1; i<=n; i++) {
			k--;
			if(k==0) break;
			if(i%2==1) {
				if(a[i]==0) {
					vi tmp = {};
					int wsk = 0;
					for(int j=i; j<=n; j++) {
						tmp.PB(a[j]);
						wsk = j;
						if(a[j]==1) break;
					}
					ans.PB({i,wsk});
					reverse(tmp.begin(),tmp.end());
					for(int j=i; j<(int)tmp.size()+i; j++) {
						a[j] =  tmp[j-i];
					}
				}
			} else {
				if(a[i]==1) {
					vi tmp = {};
					int wsk = 0;
					for(int j=i; j<=n; j++) {
						tmp.PB(a[j]);
						wsk=j;
						if(a[j]==0) break;
					}
					ans.PB({i,wsk});
					reverse(tmp.begin(),tmp.end());
					for(int j=i; j<(int)tmp.size()+i; j++) {
						a[j] =  tmp[j-i];
					}
				}
			}
		}
		for(int i=(x-1)*2+1; i<=(x-1)*2+(n/2-(x-1)); i++) {
			if(a[i]==0) {
				vi tmp = {};
				bool ok=1;
				int wsk = 0;
				for(int j=i; j<=n; j++) {
					tmp.PB(a[j]);
					wsk = j;
					if(a[j]==1) break;
					if(a[j]==0&&j==n) ok=0;
				}
				ans.PB({i,wsk});
				if(!ok) break;
				reverse(tmp.begin(),tmp.end());
				for(int j=i; j<(int)tmp.size()+i; j++) {
					a[j] =  tmp[j-i];
				}
			}
		}
		cout<<(int)ans.size()<<"\n";
		for(auto it:ans) {
			cout<<it.ST<<" "<<it.ND<<"\n";
		}
	}
			
				
					
	
}