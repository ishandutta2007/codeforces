#include<bits/stdc++.h>
using namespace std;
#define N 15050
typedef long long ll;
int n,now,X1,Y1,X2,Y2;
struct Point{
	int x,y;
}p[N];
vector<pair<int,int> > seg[N];
bool vis[N];
void Change(int x){
	now-=vis[x];
	vis[x]^=1;
	now+=vis[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>X1>>Y2>>X2>>Y1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;++i){
		int j=(i==n?1:i+1);
		if(p[i].x==p[j].x)seg[p[i].x].emplace_back(p[i].y,p[j].y);
	}
	int ans=0;
	for(int i=0;i<X2;++i){
		for(auto [L,R]:seg[i]){
			int l=min(L,R),r=max(L,R);
			l=max(l,Y1),r=min(r,Y2);
			if(l>r)continue;
			int las=now;
			Change(l),Change(r);
			if(i>X1&&L>R)ans+=(now-las)>>1;
		}
		if(i==X1)ans=now>>1;
	}
	cout<<ans<<'\n';
	return 0;
}