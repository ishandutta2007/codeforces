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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;

int main(){
	cin>>n;
	for(int i=5;i<=n;i++){
		if(n%i != 0) continue;
		if(n/i < 5) continue;
		int a = i;
		int b = n/i;
		string ans="";
		string base = "aiueo";
		for(int x=1;x<=a;x++){
			for(int y=1;y<=b;y++){
				if(1){
					int k = (x+y)%5;
					ans.pb(base[k]);
				}
				else{
					ans.pb('a');
				}
			}
			//cout << ans << endl; ans.clear();
		}
		cout << ans << endl;
		return 0;
	}
	cout << -1 << endl;
}