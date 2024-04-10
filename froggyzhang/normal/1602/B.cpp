#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n,cnt[N],Q;
vector<int> a;
vector<vector<int> > c;
void Solve(){
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	c.clear();
	c.push_back(a);
	while(true){
		vector<int> b(n);
		memset(cnt,0,sizeof(cnt));
		for(auto x:a)++cnt[x];
		for(int i=0;i<n;++i){
			b[i]=cnt[a[i]];
		}
		c.push_back(b);
		if(a==b)break;
		a=b;
	}
	cin>>Q;
	while(Q--){
		int x,k;
		cin>>x>>k;
		k=min(k,(int)c.size()-1);
		cout<<c[k][x-1]<<'\n';
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