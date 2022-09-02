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
string s;
vector<int>vec[26];
int cnt[5005][26];
int main(){
	cin>>s;
	rep(i,s.size()) vec[s[i]-'a'].pb(i);
	double ans = 0;
	rep(i,26){
	    memset(cnt,0,sizeof(cnt));
		rep(j,vec[i].size()){
			int x = vec[i][j];
			rep(k,s.size()){
				cnt[k][s[x]-'a']++;
				x = (x+1)%s.size();
			}
		}
		int mx = 0;
		rep(j,s.size()){int sum = 0;rep(k,26) sum+=(cnt[j][k]==1);
		    mx = max(mx,sum);
		}
		ans += (double)(mx) / (double)(s.size());
	}
	printf("%.12f\n",ans);
}