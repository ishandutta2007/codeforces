#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,g=3,invg=(mod+1)/g;
typedef long long ll;
struct A{
	int x,y,col;
}a[100005];
int n,b[100005],fin=0,pl[5],c[4][100005],M;
void U(int k,int x,int y){
	c[k][x]+=y;
}
vector<A> t[100005];
void Solve(int w){
	memset(c,0,sizeof(c));
	int sum[4]={0};
	for(int i=1;i<=n;i++)t[i].clear();
	for(int i=1;i<=n;i++){
		t[a[i].x].push_back(a[i]);
		if(a[i].col==pl[2])U(2,w?a[i].y:a[i].x,1),sum[2]++;
		if(a[i].col==pl[3])U(3,w?a[i].y:a[i].x,1),sum[3]++;
	}
	for(int x=1;x<=n;x++){
		for(auto u:t[x]){
			if(u.col==pl[1])sum[1]++;
			if(u.col==pl[2])U(2,w?u.y:u.x,-1),sum[2]--;
			if(u.col==pl[3])U(3,w?u.y:u.x,-1),sum[3]--;
		}
		if(sum[1]<M||sum[2]<M||sum[3]<M||fin>=M)continue; 
		int cur=0,uu=sum[3];
		for(int j=1;j<=n;j++){
			cur+=c[2][j],uu-=c[3][j];
			if(cur>=M&&uu>=M)fin=M;
		}
		return ;
	}
}
void S1(int w){
	Solve(w);
	for(int i=1;i<=n;i++)a[i].x=n-a[i].x+1;
	Solve(w);
	for(int i=1;i<=n;i++)a[i].x=n-a[i].x+1;
}
bool Check(int mid){
	M=mid,fin=0;
	for(int i=1;i<=3;i++)pl[i]=i;
	for(int p=1;p<=6;p++){
		Solve(0);
		if(fin==M)return 1;
		for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
		Solve(0);
		if(fin==M)return 1;
		for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
		next_permutation(pl+1,pl+4);
	}
	for(int i=1;i<=3;i++)pl[i]=i;
	do {
		S1(1);
		if(fin==M)return 1;
		for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
		S1(1);
		if(fin==M)return 1;
		for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
	} while(next_permutation(pl+1,pl+4));
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].col,b[i]=a[i].x;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		a[i].x=lower_bound(b+1,b+n+1,a[i].x)-b;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i].y;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		a[i].y=lower_bound(b+1,b+n+1,a[i].y)-b;
	}
	int l=0,r=n/3,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(Check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans*3;
}