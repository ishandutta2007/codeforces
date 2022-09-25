#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,ans;
struct Data{
	array<int,5> c;
	int w;
	friend bool operator < (const Data &a,const Data &b){
		return a.w<b.w;
	}
}a[N];
void Solve(int L,int R){
	unordered_map<int,bitset<25001> > mp;
	for(int i=L;i<=R;++i){
		for(int j=0;j<m;++j){
			mp[a[i].c[j]][i-L]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(ans<=a[1].w+a[i].w)continue;
		static bitset<25001> u;
		u.set();
		int fir=0;
		for(int j=0;j<m;++j){
			int x=a[i].c[j];
			if(mp.count(x)){
				u&=~mp[x];
			}
			fir=u._Find_first();
			if(L+fir>R)break;
		}
		if(L+fir<=R){
			ans=min(ans,a[i].w+a[fir+L].w);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i].c[j];
		}
		cin>>a[i].w;
	}
	sort(a+1,a+n+1);
	ans=INT_MAX;
	for(int i=1;i<=n;i+=25000){
		Solve(i,min(n,i+25000-1));
	}
	cout<<(ans==INT_MAX?-1:ans)<<'\n';
	return 0;
}