#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define y1 ysgh
#define N 123
inline int read(){
	int x=0,f=1;
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
int T,n,m,a[N][N];
char s[N];
struct step{
	int x1,y1,x2,y2,x3,y3;
};
vector<step> ans;
void Solve(){
	ans.clear();
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j]-'0';
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			if(!a[i][j])continue;
			if(j==m){
				ans.push_back({i,j,i+1,j,i+1,j-1});
				a[i][j]^=1,a[i+1][j]^=1,a[i+1][j-1]^=1;
			}
			else{
				if(a[i][j+1]){
					ans.push_back({i,j,i,j+1,i+1,j});
					a[i][j]^=1,a[i][j+1]^=1,a[i+1][j]^=1;
				}
				else{
					ans.push_back({i,j,i+1,j,i+1,j+1});
					a[i][j]^=1,a[i+1][j]^=1,a[i+1][j+1]^=1;
				}
			}
		}
	}
	for(int j=1;j<=m;++j){
		if(!a[n][j])continue;
		if(j<m&&a[n][j+1]){
			ans.push_back({n-1,j,n,j,n-1,j+1});
			ans.push_back({n-1,j,n-1,j+1,n,j+1});
			a[n][j]^=1,a[n][j+1]^=1;
		}
		else if(j<m-1&&a[n][j+2]){
			ans.push_back({n,j,n,j+1,n-1,j+1});
			ans.push_back({n,j+1,n-1,j+1,n,j+2});
			a[n][j]^=1,a[n][j+2]^=1;
		}
		else if(j==1){
			ans.push_back({n,j,n-1,j,n,j+1});
			ans.push_back({n,j,n-1,j,n-1,j+1});
			ans.push_back({n,j,n,j+1,n-1,j+1});
			a[n][j]^=1;
		}
		else{
			ans.push_back({n,j,n-1,j,n,j-1});
			ans.push_back({n,j,n,j-1,n-1,j-1});
			ans.push_back({n,j,n-1,j,n-1,j-1});
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto t:ans){
		printf("%d %d %d %d %d %d\n",t.x1,t.y1,t.x2,t.y2,t.x3,t.y3);
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}