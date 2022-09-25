#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int a[N],n,jb;
vector<vector<int> > ans;
vector<int> get_lis(int *a,int n){
	static int st[N],top,pre[N];
	top=0;
	for(int i=1;i<=n;++i){
		int p=lower_bound(st+1,st+top+1,i,[&](int i,int j){return a[i]<a[j];})-st;
		pre[i]=st[p-1];
		if(p>top||a[i]<a[st[p]])st[p]=i;
		top=max(top,p);
	}
	vector<int> V;
	for(int u=st[top];u;u=pre[u]){
		V.push_back(u);
	}
	return V;
}
vector<vector<int> > Part(int *a,int n){
	vector<vector<int> > seq;
	for(int i=1;i<=n;++i){
		if(seq.empty()||a[i]>seq.back().back()){
			seq.push_back(vector<int>({a[i]}));
		}
		else{
			int p=lower_bound(seq.begin(),seq.end(),vector<int>({a[i]}),[&](vector<int> i,vector<int> j){return i.back()<j.back();})-seq.begin();
			seq[p].push_back(a[i]);
		}
	}
	return seq;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ans.clear();
	int k=1;
	while(k*(k+1)/2<=n)++k;
	--k;
	while(n>=1){
		auto A=get_lis(a,n);
		if(A.size()>k){
			reverse(A.begin(),A.end());	
			--k;
			static int vis[N];
			++jb;
			for(auto x:A)vis[x]=jb;
			for(auto &x:A)x=a[x];
			ans.push_back(A);
			int _n=0;
			for(int i=1;i<=n;++i){
				if(vis[i]^jb)a[++_n]=a[i];
			}
			n=_n;
		}
		else{
			auto vec=Part(a,n);
			for(auto B:vec){
				ans.push_back(B);
			}
			break;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto v:ans){
		cout<<v.size();
		for(auto x:v)cout<<' '<<x;
		cout<<'\n';
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