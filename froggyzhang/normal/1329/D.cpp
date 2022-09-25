#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T;
int n,m,c[N],cnt[26],a[N];
char t[N];
set<pii> s[26][26];
vector<pii> ans;
int pre[N],suf[N],del[N];
inline void Del(int x){
	del[x]=1;
	suf[pre[x]]=suf[x];
	pre[suf[x]]=pre[x];	
}
void Op(int l,int r){
	int L=T.order_of_key(l);
	int R=T.order_of_key(r+1);
	++L;
	if(L>R)return;
	ans.emplace_back(L,R);
	vector<int> D;
	for(auto it=T.lower_bound(l);it!=T.end()&&(*it)<=r;++it)D.push_back(*it);
	for(auto x:D)T.erase(x);
}
void Solve(){
	cin>>(t+1);
	n=strlen(t+1);
	T.clear();
	ans.clear();
	for(int i=1;i<=n;++i){
		T.insert(i);
		a[i]=t[i]-'a';
	}
	m=0;
	for(int i=0;i<26;++i){
		cnt[i]=0;
		for(int j=0;j<26;++j)
			s[i][j].clear();
	}
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1]){
			c[++m]=i;
			++cnt[a[i]];		
		}
	}
	for(int i=1;i<=m;++i){
		pre[i]=i-1,suf[i]=i+1;del[i]=0;
	}
	for(int i=1;i<m;++i){
		if(a[c[i]]^a[c[i+1]]){
			s[a[c[i]]][a[c[i+1]]].emplace(i,i+1);
			s[a[c[i+1]]][a[c[i]]].emplace(i,i+1);
		}
	}
	while(true){
		int u=max_element(cnt,cnt+26)-cnt,v=-1;
		for(int i=0;i<26;++i){
			if(u^i&&!s[u][i].empty()){
				v=i;break;
			}
		}
		if(!~v)break;
		auto [l,r]=*s[u][v].begin();
		s[u][v].erase(s[u][v].begin());
		s[v][u].erase(make_pair(l,r));
		--cnt[u],--cnt[v];
		u=a[c[l]],v=a[c[r]];
		int tl=a[c[pre[l]]],tr=a[c[suf[r]]];
		if(pre[l]&&a[c[l]]^tl){
			s[tl][u].erase(make_pair(pre[l],l));
			s[u][tl].erase(make_pair(pre[l],l));
		}
		if(suf[r]<=m&&a[c[r]]^tr){
			s[v][tr].erase(make_pair(r,suf[r]));
			s[tr][v].erase(make_pair(r,suf[r]));
		}
		if(pre[l]&&suf[r]<=m&&tl^tr){
			s[tl][tr].emplace(pre[l],suf[r]);
			s[tr][tl].emplace(pre[l],suf[r]);
		}
		Op(c[l]+1,c[r]);
		Del(l),Del(r);
	}
	vector<int> tp({0});
	for(int i=1;i<=m;++i){
		if(!del[i])tp.push_back(c[i]);
	}
	tp.push_back(n);
	for(int i=0;i<(int)tp.size()-1;++i){
		Op(tp[i]+1,tp[i+1]);
	}
	cout<<ans.size()<<'\n';
	for(auto [l,r]:ans){
		cout<<l<<' '<<r<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}