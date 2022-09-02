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
int nxt[200005];
bool used[200005];
int main(){
	cin>>s;
	queue<int>q0,q1;
	for(int i=0;i<s.size();i++){
		if(s[i] == '0'){
			if(q1.size()){
				int Q = q1.front(); q1.pop();
				nxt[Q] = i+1;
				q0.push(i+1);
			}
			else{
				q0.push(i+1);
			}
		}
		else{
			if(q0.size()){
				int Q = q0.front(); q0.pop();
				nxt[Q] = i+1;
				q1.push(i+1);
			}
			else{
				puts("-1"); return 0;
			}
		}
	}
	if(q1.size()){
		puts("-1"); return 0;
	}
	vector<vector<int> >ans;
	for(int i=1;i<=s.size();i++){
		if(used[i]) continue;
		int cur = i;
		vector<int>vi;
		while(1){
			vi.pb(cur);
			used[cur] = 1;
			if(nxt[cur] == 0) break;
			cur = nxt[cur];
		}
		ans.pb(vi);
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d",ans[i].size());
		rep(j,ans[i].size()){
			printf(" %d",ans[i][j]);
		}
		puts("");
	}
}