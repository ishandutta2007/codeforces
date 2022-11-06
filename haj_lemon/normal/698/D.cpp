#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define N 10
#define M 1010 
using namespace std;
struct Po{ll x,y;}a[N],b[M];
vector<int> c[N][M];
int m,n,ans;
bool v1[N],v2[M];
bool ch(Po x,Po y,Po z){
	if (x.x>y.x)swap(x,y);
	if (z.x<x.x||z.y<min(x.y,y.y)||z.x>y.x||z.y>max(x.y,y.y)) return 0;
	return ((y.x-x.x)*(z.y-x.y)==(y.y-x.y)*(z.x-x.x));
}
bool get(int dep,vector<int> x){
	if (dep>n||x.size()==0) return 1;
	int g=x[x.size()-1];
	bool ans=0;
	for (int i=1;i<=n;i++){
		if (v1[i]&&c[i][g].size()<n){
			bool p=1;vector<int> y=x;y.pop_back();v1[i]=0;
			for (auto j:c[i][g]){
				if (v2[j]==2) p=0;
				if (v2[j]==1){v2[j]=0;y.pb(j);}
			}
			if (y.size()+dep>n) p=0;
			if (p)ans|=get(dep+1,y);
			for (int j=x.size()-1;j<y.size();j++)v2[y[j]]=1;
			v1[i]=1;
		}
	}
	return ans;
}
int main(){
//	freopen("d.in","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	for (int i=1;i<=m;i++)cin>>b[i].x>>b[i].y;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=m;k++)
				if (k!=j)if (ch(a[i],b[j],b[k]))c[i][j].pb(k);
	for (int i=1;i<=m;i++)v2[i]=1;
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++)v1[i]=1;
		v2[j]=2;
		vector<int> no;no.clear();no.pb(j);
		ans+=get(1,no);
		v2[j]=1;
	}
	cout<<ans<<endl;
	return 0;
}