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
int m;
string S;
ll dp[3005][3005];
set<string>fb;

int A[3005];
string SS;
void MP(){
    memset(A,0,sizeof(A));
	A[0] = -1;
	int j = -1;
	for (int i = 0; i < SS.size(); i++) {
	  while (j >= 0 && SS[i] != SS[j]) j = A[j];
	  j++;
	  A[i+1] = j;
	}
}

int main(){
	cin>>m;
	for(int i=0;i<m;i++){
		char ch ; scanf(" %c",&ch); S.pb(ch);
	}
	fb.insert("0011");
	fb.insert("0101");
	fb.insert("1110");
	fb.insert("1111");

	for(int i=0;i<m;i++){
		for(int j=i;j<m;j++){
			string st = "";
			for(int use=1;use<=4;use++){
				int pt = j-use+1;
				reverse(st.begin(),st.end());
				st.pb(S[pt]);
				reverse(st.begin(),st.end());
				if(use == 4 && fb.find(st) != fb.end()) continue;
				if(j-use == i-1){
					dp[i][j] += 1; break;
				}
				else{
					dp[i][j] += dp[i][j-use];
					if(dp[i][j] >= mod) dp[i][j]-=mod;
				}
			}
		}
	}
	ll ans = 0;
	
	for(int i=0;i<m;i++){
	    reverse(SS.begin(),SS.end()); SS.pb(S[i]); reverse(SS.begin(),SS.end());
	    MP();int x = 0;
	    for(int xx=0;xx<3005;xx++) x=max(x,A[xx]);

	//	cout << i <<" "<<i-A[i+1] << endl;
		for(int j=0;j<=i-x;j++){
			ans += dp[j][i];
		}
		ans = (ans%mod+mod)%mod;
		cout<<ans<<endl;
	}
}