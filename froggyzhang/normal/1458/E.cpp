#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
#define N 200020
pii q[N];
int n,m;
vector<int> X,Y;
set<pii> S;
map<int,int> mnx,mny;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		S.emplace(x,y);
		X.push_back(x);
		Y.push_back(y);
		if(!mnx.count(x)||mnx[x]>y)mnx[x]=y;
		if(!mny.count(y)||mny[y]>x)mny[y]=x;
	}
	for(int i=1;i<=m;++i){
		cin>>q[i].first>>q[i].second;
		X.push_back(q[i].first);
		Y.push_back(q[i].second);
	}
	int x=0,y=0;
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.push_back(inf);
	Y.push_back(inf);
	while(x<=1e9){
		int dx=(*lower_bound(X.begin(),X.end(),x))-x;
		int dy=(*lower_bound(Y.begin(),Y.end(),y))-y;
		x+=min(dx,dy),y+=min(dx,dy);
		while(true){
			bool stop=true;
			if(mnx.count(x)&&mnx[x]<=y)++x,stop=false;
			if(mny.count(y)&&mny[y]<=x)++y,stop=false;
			if(stop)break;
		}
		S.emplace(x,y);
		++x,++y;
	}
	for(int i=1;i<=m;++i){
		cout<<(S.count(q[i])?"LOSE\n":"WIN\n");
	}
	return 0;
}