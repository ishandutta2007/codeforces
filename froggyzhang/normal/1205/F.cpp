#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int mx=100;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
int dp[N][N*N],pre[N][N*N];
void init(){
	dp[1][0]=1;
	for(int i=1;i<mx;++i){
		int lim=i*(i-1)/2;
		for(int j=0;j<=lim;++j){
			if(!dp[i][j])continue;
			for(int k=2;i+k-1<=mx;++k){
				dp[i+k-1][j+(k-1)*k/2]=1;
				pre[i+k-1][j+(k-1)*k/2]=k;
			}
			for(int k=4;i+k-1<=mx;++k){
				dp[i+k-1][j+1]=1;
				pre[i+k-1][j+1]=-k;
			}
		}
	}
}
vector<int> p;
void calc(int n,int k){
	if(!k)return;
	int z=pre[n][k];
	p.push_back(z);
	if(z>0){ // 
		calc(n-z+1,k-z*(z-1)/2);
	}
	else{  // 
		z=-z;
		calc(n-z+1,k-1);
	}
}
void dfs(int u,int l,int r,int tp){
	if(u==p.size()){
		printf("%d\n",l);
		return;
	}
	int z=p[u];
	if(z>0){ // 
		if(tp){
			for(int i=l;i<l+z-1;++i){
				printf("%d ",i);
			}
			dfs(u+1,l+z-1,r,tp^1);
		}
		else{
			for(int i=r;i>r-z+1;--i){
				printf("%d ",i);
			}
			dfs(u+1,l,r-z+1,tp^1);
		}
	}
	else{  // 
		z=-z;
		for(int i=0;i<z-1;++i){
			if(i&1)printf("%d ",r-(z>>1)+(i>>1)+1+(!(z&1)));
			else printf("%d ",l+(z>>1)-(i>>1)-1);
		}
		dfs(u+1,l+(z>>1),r-(z>>1)+(!(z&1)),tp);
	}
}	
int main(){
	T=read();
	init();
	while(T--){
		int n=read(),k=read();
		k-=n;
		if(k<0||!dp[n][k]){
			puts("NO");
			continue;
		}
		puts("YES");
		p.clear();
		calc(n,k);
		reverse(p.begin(),p.end());
		dfs(0,1,n,1);
	}
	return 0;
}