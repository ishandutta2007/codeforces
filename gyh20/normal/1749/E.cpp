#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
vector<int>A[200002],B[200002],C[200002],D[200002];
int n,m;
char s[200002]; 
inline void Get1(re int x,re int y){
	if(x==0)return;
	A[x][y]=1;
	if(B[x-1][y-1]<B[x-1][y+1])Get1(x-1,y-1);
	else Get1(x-1,y+1);
}
inline void Get2(re int x,re int y){
	if(y==0)return;
	A[x][y]=1;
	if(C[x][y]==0)Get2(x-1,y-1);
	else if(C[x][y]==1)Get2(x+1,y-1);
	else if(C[x][y]==2)Get2(x-1,y+1);
	else Get2(x+1,y+1);
}
inline void Out(){
	puts("YES");
	for(re int i=1;i<=n;++i,puts(""))
		for(re int j=1;j<=m;++j)
			putchar(A[i][j]?'#':'.');
}
int main(){
	int t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=0;i<=n+1;++i)A[i].clear(),A[i].resize(m+2),B[i].clear(),B[i].resize(m+2),C[i].clear(),C[i].resize(m+2),D[i].clear(),D[i].resize(m+2);
		for(re int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(re int j=1;j<=m;++j)A[i][j]=(s[j]=='#');
		}
		deque<int>X,Y;
		for(re int j=0;j<=m;++j)B[0][j]=B[n+1][j]=1e9;
		for(re int j=1;j<=n;++j)B[j][0]=0,X.push_back(j),Y.push_back(0);;
		for(re int i=0;i<=n+1;++i)
			for(re int j=1;j<=m+1;++j)B[i][j]=1e9;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				D[i][j]=A[i-1][j]||A[i+1][j]||A[i][j-1]||A[i][j+1];
		while(X.size()){
			int x=X.front(),y=Y.front();X.pop_front();Y.pop_front();
			if(x>1&&y>1&&!D[x-1][y-1]){
				if(B[x][y]+(A[x-1][y-1]==0)<B[x-1][y-1]){
					B[x-1][y-1]=B[x][y]+(A[x-1][y-1]==0),C[x-1][y-1]=3;
					if(A[x-1][y-1]==0)X.push_back(x-1),Y.push_back(y-1);
					else X.push_front(x-1),Y.push_front(y-1);
				}
			}
			if(x>1&&y<m&&!D[x-1][y+1]){
				if(B[x][y]+(A[x-1][y+1]==0)<B[x-1][y+1]){
					B[x-1][y+1]=B[x][y]+(A[x-1][y+1]==0),C[x-1][y+1]=1;
					if(A[x-1][y+1]==0)X.push_back(x-1),Y.push_back(y+1);
					else X.push_front(x-1),Y.push_front(y+1);
				}
			}
			if(x<n&&y>1&&!D[x+1][y-1]){
				if(B[x][y]+(A[x+1][y-1]==0)<B[x+1][y-1]){
					B[x+1][y-1]=B[x][y]+(A[x+1][y-1]==0),C[x+1][y-1]=2;
					if(A[x+1][y-1]==0)X.push_back(x+1),Y.push_back(y-1);
					else X.push_front(x+1),Y.push_front(y-1);
				}
			}
			if(x<n&&y<m&&!D[x+1][y+1]){
				if(B[x][y]+(A[x+1][y+1]==0)<B[x+1][y+1]){
					B[x+1][y+1]=B[x][y]+(A[x+1][y+1]==0),C[x+1][y+1]=0;
					if(A[x+1][y+1]==0)X.push_back(x+1),Y.push_back(y+1);
					else X.push_front(x+1),Y.push_front(y+1);
				}
			}
		}
		int ia=1e9;
		for(re int j=1;j<=n;++j)ia=min(ia,B[j][m]);
		if(ia<=1e8){
			for(re int i=1;i<=n;++i)if(B[i][m]==ia){Get2(i,m);break;}
			Out();
			continue;
		}puts("NO");
		
	}
}