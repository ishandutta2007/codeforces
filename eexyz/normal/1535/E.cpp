#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 300005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define ll long long
int a[N],c[N],fa[N][20],ans_,dep[N];
long long ans;
int find(int x){
	for(int i=18;~i;--i)if(a[fa[x][i]])x=fa[x][i];return x;
}
int fat(int x,int y){
	for(int i=18;~i;--i)
		if((y>>i)&1)x=fa[x][i];
	return x;
}
ll solve(int x,int y,int sy){//
	if(a[y]>=sy){a[y]-=sy;ans_=0;return 1ll*sy*c[y];}
	else{
		ll ret=1ll*a[y]*c[y];sy-=a[y];a[y]=0;
		if(x==y)return ans_=sy,ret;
		return ret+solve(x,fat(x,dep[x]-dep[y]-1),sy);
	}
}
int q,i,ty,x,j,y;
int main(){
	ios::sync_with_stdio(false);
	cin>>q>>a[0]>>c[0];
	for(i=1;i<=q;++i){
		cin>>ty;
		if(ty==1){
			cin>>fa[i][0]>>a[i]>>c[i];dep[i]=dep[fa[i][0]]+1;
			for(j=1;j<=18;++j)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else{
			cin>>x>>y;
			ans=solve(x,find(x),y);
			cout<<y-ans_<<" "<<ans<<"\n";
		}
		cout.flush();
	}
}