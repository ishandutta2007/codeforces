#include <bits/stdc++.h>
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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[1005],b[1005];
int main(){
	cin>>n;
	repn(i,n){
		cin>>a[i];
		b[i] = a[i]-a[i-1];
	}
	vector<int>ans;
	repn(i,n){
		repn(j,n){
			if(j-i>=1){
				if(b[j] != b[j-i]){
					goto fail;
				}
			}
		}
		ans.pb(i); fail:;
	}
	cout << ans.size() << endl;
	rep(i,ans.size()) cout << ans[i] << " ";
	cout << endl;
}