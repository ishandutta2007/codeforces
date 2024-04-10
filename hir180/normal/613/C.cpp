#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
void dmp(vector<int>&a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
}
int n;
string make_str(vector<int>a){
				string ans;
				int sum = 0, odd = -1;
				rep(i,a.size()){
					sum += a[i];
					if(a[i]&1) odd = i;
				}
				ans.resize(sum,'a');
				if(odd != -1) ans[sum/2] = 'a'+odd;
				int cur = 0;
				rep(aa,n){
					if(aa == odd) a[aa]--;
					rep(k,a[aa]/2){
						ans[cur] = 'a'+aa;
						ans[sum-1-cur] = 'a'+aa;
						cur++;
					}
				}
				return ans;
}
int a[32];
int main(){
	cin >> n;
	rep(i,n) cin >> a[i];
	for(int i=100000;i>=1;i--){
		if(i%2 == 1){
			//all same palindrome
			int cnt = 0,sum = 0,odd = -1;
			rep(jj,n){
				int j = a[jj];
				if(j%i != 0) cnt+=2;
				cnt += (j/i)%2;
				sum += (j/i);
				if( (j/i)%2 == 1 ) odd = jj;
			}
			if(cnt >= 2) continue;
			printf("%d\n",i);
			{
				vector<int>x;
				rep(jj,n) x.pb(a[jj]/i);
				string ans = make_str(x);
				rep(q,i) cout<<ans;
				cout<<endl;
				return 0;
			}
		}
		else{
			//all same string (without reversal)
			int cnt = 0,sum = 0;
			rep(jj,n){
				int j = a[jj];
				if(j%i != 0) cnt+=2;
				cnt += 0;
				sum += (j/i);
			}
			if(cnt >= 2) continue;
			printf("%d\n",i);
			{
				string ans = "";
				rep(jj,n){
					rep(k,a[jj]/i) ans.pb('a'+jj);
				}
				rep(q,i){
					cout<<ans;
					reverse(ans.begin(),ans.end());
				}
				cout<<endl;
				return 0;
			}
		}
	}
	puts("0");
	rep(i,n){
		rep(j,a[i]){
			printf("%c",'a'+i);
		}
	}
	puts("");
}