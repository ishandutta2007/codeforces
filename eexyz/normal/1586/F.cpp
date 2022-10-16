#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,k,tt[N][14],i,ans,j,gg;
void cons(int l,int r,int x,int dep){
	if(l==r){
		return ;
	}
	int tmp=(r-l+1)/k,cc=0;
	for(int i=l;i<=r;i+=tmp){
		++cc;
		if(x<i+tmp){
			tt[x][dep]=cc;cons(i,i+tmp-1,x,dep+1);return ;
		} 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	gg=1;
	while(gg<n)gg=gg*k,++ans;
	for(i=1;i<=n;++i){
		cons(1,gg,i,1);
//		for(j=1;j<=ans;++j)cout<<tt[i][j]<<" ";cout<<"\n";
	}cout<<ans<<"\n";
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n;++j){
			for(k=1;;++k){
				if(tt[i][k]!=tt[j][k]){cout<<k<<" ";break;} 
			}
		}
	}
}