#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define l(x) (x&-x)
struct dot{
	int x,y,z,pos;
}d[N];
inline bool cmp1(dot aa,dot bb){return aa.x<bb.x;}
inline bool cmp2(dot aa,dot bb){return aa.y<bb.y;}
inline bool cmp3(dot aa,dot bb){return aa.z<bb.z;}
int n,i,vis[N];
void solve_(int l,int r){
	sort(d+l,d+r+1,cmp3);
	for(int i=l;i<=r;i+=2){
		cout<<d[i].pos<<" "<<d[i+1].pos<<"\n";
	}
}
void solve(int l,int r){
	sort(d+l,d+r+1,cmp2);
	for(int j,i=l;i<=r;i=j+1){
		j=i+1;
		while(j<=r&&d[j].x==d[i+1].x)++j;
		--j;
		if((j-i+1)&1)--j;
		solve_(i,j);
	}
}
int j,V,mn,pos;
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>d[i].x>>d[i].y>>d[i].z;
	for(i=1;i<=n;++i){
		if(vis[i])continue;mn=2e9;
		for(j=i+1;j<=n;++j){
			if(vis[j])continue;
			V=abs(d[j].x-d[i].x)+abs(d[j].y-d[i].y)+abs(d[j].z-d[i].z);
			if(V<mn)mn=V,pos=j;
		}
		vis[pos]=vis[i]=1;
		cout<<i<<" "<<pos<<"\n";
	} 
}