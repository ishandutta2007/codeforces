#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll x;
string s;
deque<int>v[160101];
int par[160001];
int l[160001],r[160001];
char tp[160001];
int nd;
stack<int>st;
vector<int>ch[160101];
vector<pair<ll,bool> >ans;
int sum=0;
int dp[160101];
bool tk[160101];
void dfs(int id,bool w){
	if(s[l[id]]=='*'){
		ans.push_back({l[id],w});
		sum+=w;
	}
	for(auto cur:ch[id]){
		bool hv=false;
		dfs(cur,w&&tk[cur]);
	}
}
void dfs2(int id){
	if(s[l[id]]=='*') dp[id]=1;
	if(s[l[id]]=='(' && tp[id]=='S') dp[id]=1e9;
	for(auto cur:ch[id]){
		bool hv=false;
		if(id==1 || s[l[id]]=='(' && tp[id]=='P'){
			dfs2(cur);tk[cur]=true;
			dp[id]=dp[id]+dp[cur];
		}
		else{
			dfs2(cur);dp[id]=min(dp[id],dp[cur]);
		}
	}
	if(s[l[id]]=='(' && tp[id]=='S'){
		for(auto cur:ch[id]){
			if(dp[cur]==dp[id]){
				//cout << "!!! " << cur << endl;
				tk[cur]=true;
				break;
			}
		}
	}
}
void solve(){
	cin >> x;getline(cin,s);
	int pf=0;
	int ptr=-1;
	nd=1;
	ans.clear();
	for(auto c:s){
		ptr++;
		if(c!='(' && c!=')') continue;
		if(c=='(') pf++;
		else pf--;
		v[pf].push_back(ptr);
	}
	ptr=-1;
	pf=0;
	st.push(1);
	sum=0;
	for(auto c:s){
		ptr++;
		if(c=='P' || c=='S') tp[st.top()]=c;
		if(c!='*' && c!='(' && c!=')') continue;
		if(c==')'){
			pf--;st.pop();v[pf].pop_front();continue;
		}
		if(c=='*'){
			++nd;l[nd]=r[nd]=ptr;
			par[nd]=st.top();ch[st.top()].push_back(nd);continue;
		}
		++nd;
		l[nd]=ptr;r[nd]=v[pf].front();
		pf++;
		v[pf].pop_front();
		par[nd]=st.top();ch[st.top()].push_back(nd);
		st.push(nd);
	}
	dfs2(1);
	dfs(1,1);
	cout << "REVOLTING ";
	for(auto cur:ans){
		if(cur.se) cout << 1LL*x*sum << ' ';
		else cout << 0 << ' ';
	}
	cout << '\n';
	for(int i=0; i<nd+100 ;i++) v[i].clear();
	for(int i=0; i<nd+100 ;i++) ch[i].clear();
	for(int i=0; i<nd+100 ;i++) dp[i]=0,tk[i]=0;
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}