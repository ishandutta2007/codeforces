#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define l(x) (x&-x)
struct dot{
	int x,y,z,pos;
}d[N];
int X;
inline bool cmp(dot aa,dot bb){
	return aa.x+aa.y+aa.z<bb.x+bb.y+bb.z;
}
int j,V,mn,pos,n,i,vis[N],zz;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>d[i].x>>d[i].y>>d[i].z,d[i].pos=i;
	sort(d+1,d+n+1,cmp); 
	for(i=1;i<=n;++i){
		if(vis[i])continue;mn=2e9;
		zz=min(n,i+20000);
		for(j=i+1;j<=zz;++j){
			if(vis[j])continue;
			V=abs(d[j].x-d[i].x)+abs(d[j].y-d[i].y)+abs(d[j].z-d[i].z);
			if(V<mn)mn=V,pos=j;
		}
		vis[pos]=vis[i]=1;
		cout<<d[i].pos<<" "<<d[pos].pos<<"\n";
	} 
}