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
string a,b;
vector<int>pos,pos2;
int main(){
	cin>>a>>b;
	int nxt = 0;
	pos.pb(-1);
	for(int i=0;i<b.size();i++){
		while(a[nxt] != b[i]) nxt++;
		pos.pb(nxt);nxt++;
	}
	nxt = a.size()-1;
	pos2.pb(a.size());
	for(int i=b.size()-1;i>=0;i--){
		while(a[nxt] != b[i]) nxt--;
		pos2.pb(nxt);nxt--;
	}
	int ans = 0;
	for(int i=0;i<pos.size();i++){
		int L = pos[i]+1;
		int R = pos2[pos.size()-1-i]-1;
		//cout << L << " " << R << endl;
		ans = max(ans,R-L+1);
	}
	cout<<ans<<endl;
}