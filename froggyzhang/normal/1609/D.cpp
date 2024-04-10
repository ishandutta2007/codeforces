#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
int f[N],siz[N];
int n,Q;
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
multiset<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		f[i]=i;
		siz[i]=1;
		q.insert(1);
	}
	int cnt=1;
	while(Q--){
		int x,y;
		cin>>x>>y;
		int fx=getf(x),fy=getf(y);
		if(fx^fy){
			f[fy]=fx;
			q.erase(q.find(siz[fx]));
			q.erase(q.find(siz[fy]));
			siz[fx]+=siz[fy];
			q.insert(siz[fx]);
		}
		else{
			++cnt;
		}
		int ans=0;
		auto it=q.end();
		for(int i=1;i<=cnt;++i){
			if(it==q.begin())break;
			--it;
			ans+=*it;	
		}
		cout<<ans-1<<'\n';
	}
	return 0;
}