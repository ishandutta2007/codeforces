#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int n,siz[N],p[N],f[N];
inline int Ask(vector<int> A,vector<int> B,int u){
	cout<<A.size()<<'\n';
	for(auto x:A)cout<<x<<' ';
	cout<<'\n';
	cout<<B.size()<<'\n';
	for(auto x:B)cout<<x<<' ';
	cout<<'\n';
	cout<<u<<endl;
	int x;
	cin>>x;
	return x;
}
set<int> S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	siz[1]=n;
	vector<int> tmp;
	for(int j=2;j<=n;++j){
		tmp.push_back(j);
	}
	for(int i=2;i<=n;++i){
		siz[i]=Ask({1},tmp,i);
	}
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){return siz[i]<siz[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		function<void(vector<int>)> dfs=[&](vector<int> v)->void{
			if(v.empty())return;
			int cnt=Ask({1},v,u);
			if(cnt==v.size()){
				for(auto x:v)S.erase(x),f[x]=u;
				return;
			}
			if(!cnt)return;
			vector<int> A,B;
			for(int i=0;i<(int)v.size();++i){
				if(i&1)B.push_back(v[i]);
				else A.push_back(v[i]);
			}
			dfs(A),dfs(B);
		};
		if(siz[u]>1){
			dfs(vector<int>(S.begin(),S.end()));		
		}
		S.insert(u);
	}
	cout<<"ANSWER\n";
	for(int i=2;i<=n;++i){
		cout<<f[i]<<' '<<i<<'\n';
	}
	cout<<endl;
	return 0;
}