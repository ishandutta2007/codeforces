#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
int p[N],sz[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
multiset<int>s,b;
ll sum=0;
int use=0;
void join(int x,int y){
	x=find(x);y=find(y);
	if(x==y){
		use++;
		return;
	}
	auto it=s.find(sz[x]);
	if(it==s.end()){
		it=b.find(sz[x]);
		sum-=sz[x];
		b.erase(it);
	}
	else s.erase(it);
	it=s.find(sz[y]);
	if(it==s.end()){
		it=b.find(sz[y]);
		sum-=sz[y];
		b.erase(it);
	}
	else s.erase(it);
	p[x]=y;
	sz[y]+=sz[x];
	s.insert(sz[y]);
}
void fix(){
	while(!s.empty() && b.size()<use+1){
		auto it=s.end();--it;
		sum+=*it;
		b.insert(*it);
		s.erase(it);
	}
	if(!s.empty()){
		auto it=s.end();--it;
		b.insert(*it);sum+=*it;
		s.erase(it);
		sum-=*b.begin();
		s.insert(*b.begin());
		b.erase(b.begin());
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		p[i]=i;sz[i]=1;
		s.insert(1);
	}
	fix();
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		join(u,v);
		fix();
		cout << sum-1 << '\n';
		/*cout << "S:";
		for(auto c:s) cout << c << ' ';
		cout <<'\n';
		cout << "B: ";
		for(auto c:b) cout << c << ' ';
		cout << endl;*/
	}
}