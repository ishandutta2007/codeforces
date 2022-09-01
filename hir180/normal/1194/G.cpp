#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<int>vec;
vector<int>divv(vector<int>x,int D){
	vector<int>y = x;
	ll up = 0;
	for(int i=0;i<y.size();i++){
		up = up*10+y[y.size()-1-i];
		y[y.size()-1-i] = up/D;
		up %= D;
	}
	return y;
}
ll dp[16][16][11][11][2][105],ans;
signed main(){
	string s; cin>>s;
	for(int i=0;i<s.size();i++){
		vec.pb(s[s.size()-1-i]-'0');
		ans = 10LL*ans+(s[i]-'0');
		ans %= mod;
	}
	//cout << ans << endl;
	for(int x=1;x<=9;x++){
		for(int y=x+1;y<=9;y++){
			int w = __gcd(x,y);
			int X = x/w, Y = y/w;
			int xx[5],yy[5];
			for(int z=0;z<w;z++){
				xx[z] = (x/w)*(z+1);
				yy[z] = (y/w)*(z+1);
			}
			vector<int>vi = divv(vec,Y);
			rep(a,(1<<w)) rep(b,(1<<w)) rep(c,11) rep(d,11) rep(e,2) rep(pos,105) dp[a][b][c][d][e][pos] = 0;
			dp[0][0][0][0][0][0] = 1;
			for(int pos=0;pos<vi.size();pos++){
				rep(a,(1<<w))rep(b,(1<<w))rep(c,11)rep(d,11)rep(e,2){
					if(dp[a][b][c][d][e][pos] == 0) continue;
					rep(nxt,10){
						int A = a, B = b, E = e;
						int C = c+nxt*X; rep(z,w) if(C%10 == xx[z]) A |= (1<<z);
						int D = d+nxt*Y; rep(z,w) if(D%10 == yy[z]) B |= (1<<z);
						if(nxt<vi[pos]) E = 0;
						else if(nxt>vi[pos]) E = 1;
						dp[A][B][C/10][D/10][E][pos+1] += dp[a][b][c][d][e][pos];
					}
				}
				rep(a,(1<<w))rep(b,(1<<w))rep(c,11)rep(d,11)rep(e,2) dp[a][b][c][d][e][pos+1]%=mod;
			}
			rep(a,(1<<w))rep(b,(1<<w))rep(c,11)rep(d,11) {
				int A = a, B = b;
				rep(z,w) if(c == xx[z]) A |= (1<<z);
				rep(z,w) if(d == yy[z]) B |= (1<<z);
			    if((A&B) == (1<<w)/2) ans += dp[a][b][c][d][0][vi.size()]*2LL;
			}
			//cout << x << " " << y << " " << ans << endl;
		}
	}
	cout << (ans%mod+mod)%mod << endl;
}