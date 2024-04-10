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

ll m[11];
ll pos[100005][11];
string s;

int main(){
	cin>>s;
	for(int i=1;i<=10;i++){
		m[i] = (m[i-1]+i)%11;
	}
	int n = s.size();
	for(int i=0;i<11;i++) pos[n-1][i] = n-1;
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<11;j++){
			//pos[i][j]
			if(s[i+1]-'0' >= j){
				pos[i][j] = i;
			}
			else{
				int nw = m[(10+j)%11]+(s[i+1]-'0')+1+9;
				nw %= 11;
				pos[i][j] = pos[i+1][nw];
				//cout<<i<<" "<<j<<" "<<i+1<<" "<<nw<<endl;
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '0') continue;
		ans += (pos[i][s[i]-'0']-i+1);
		//cout << pos[i][s[i]-'0'] << " " << i << endl;
	}
	cout << ans << endl;
	return 0;
}