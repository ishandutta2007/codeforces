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
char a[300005],b[300005];
int n,m;
int main(){
	scanf("%s%s",&a,&b);
	n = strlen(a);
	m = strlen(b);
	sort(a,a+n, greater<char>());
	sort(b,b+m);
	string ans = "";
	int v0 = n-1, v1 = m-1;
	rep(i,n){
		if(a[v0] >= b[v1]){
			string p="", q="";
			for(int j=i;j<n;j++){
				if(j%2==0)p.pb(a[v0--]);
				else q.pb(b[v1--]);
			}
			if(n%2 == 0) swap(p, q);
			int pp=0,qq=0;
			while(1){
			    if(ans.size() == n) break; else ans.pb(p[pp++]);
			    if(ans.size() == n) break; else ans.pb(q[qq++]);
			}
			break;
		}
		else{
			if(i%2 == 0){
				ans.pb(a[v0--]);
			}
			else{
				ans.pb(b[v1--]);
			}
		}
	}
	cout << ans << endl;
}