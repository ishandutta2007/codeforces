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
const int t[4]={7,11,13,14};
void Solve(int x,int y){
	int A=a[x][y]+(a[x][y+1]<<1)+(a[x+1][y]<<2)+(a[x+1][y+1]<<3);
	for(int i=0;i<16;++i){
		int p=0;
		for(int j=0;j<4;++j){
			if(i>>j&1)p^=t[j];
		}
		if(p==A){
			if(i&1)ans.push_back({x,y,x+1,y,x,y+1});
			if(i&2)ans.push_back({x,y,x,y+1,x+1,y+1});
			if(i&4)ans.push_back({x,y,x+1,y,x+1,y+1});
			if(i&8)ans.push_back({x+1,y,x,y+1,x+1,y+1});
			return;
		}
	}
}
void Solve(){
	ans.clear();
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j]-'0';
		}
	}
	vector<step> tmp;
	if(n&1){
		for(int j=1;j<=m;++j){
			if(!a[n][j])continue;
			if(j==m){
				ans.push_back({n,m,n-1,m,n-1,m-1});
			}
			else{
				ans.push_back({n,j,n-1,j,n-1,j+1});
			}
		}
		--n;
	}
	for(auto t:ans){
		a[t.x1][t.y1]^=1;
		a[t.x2][t.y2]^=1;
		a[t.x3][t.y3]^=1;
	}
	if(m&1){
		for(int i=1;i<=n;++i){
			if(!a[i][m])continue;
			if(i==n){
				tmp.push_back({n,m,n,m-1,n-1,m-1});
			}
			else{
				tmp.push_back({i,m,i,m-1,i+1,m-1});
			}
		}
		--m;
	}
	for(auto t:tmp){
		a[t.x1][t.y1]^=1;
		a[t.x2][t.y2]^=1;
		a[t.x3][t.y3]^=1;
		ans.push_back(t);
	}
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j+=2){
			Solve(i,j);
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