#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],t;
char s[102][102]; 
const int M=998244353;
struct node{
	int a,b,c,d,e,f;
};
vector<node>ans;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
inline void calc(){
//	putchar(s[n-1][m-1]),putchar(s[n-1][m]),putchar(s[n][m-1]),putchar(s[n][m]),puts("");
	if(s[n-1][m-1]=='1'&&s[n][m-1]=='1'&&s[n-1][m]=='1'&&s[n][m]=='1')return;
	if(s[n-1][m-1]=='0'&&s[n][m-1]=='0'&&s[n-1][m]=='0'){
		ans.push_back((node){n-1,m-1,n,m-1,n-1,m});
		s[n-1][m-1]^=1,s[n][m-1]^=1,s[n-1][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'&&s[n][m-1]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n-1,m-1,n,m-1,n,m});
		s[n-1][m-1]^=1,s[n][m-1]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'&&s[n-1][m]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n-1,m-1,n-1,m,n,m});
		s[n-1][m-1]^=1,s[n-1][m]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n][m-1]=='0'&&s[n-1][m]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n,m-1,n-1,m,n,m});
		s[n][m-1]^=1,s[n-1][m]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'&&s[n][m-1]=='0'){
		ans.push_back((node){n-1,m-1,n-1,m,n,m});
		s[n-1][m-1]^=1,s[n-1][m]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'&&s[n-1][m]=='0'){
		ans.push_back((node){n-1,m,n,m-1,n,m});
		s[n-1][m]^=1,s[n][m-1]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n][m-1]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n-1,m-1,n-1,m,n,m});
		s[n-1][m-1]^=1,s[n-1][m]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n-1,m,n,m-1,n-1,m-1});
		s[n-1][m]^=1,s[n][m-1]^=1,s[n-1][m-1]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'&&s[n][m]=='0'){
		ans.push_back((node){n-1,m,n,m-1,n,m});
		s[n-1][m]^=1,s[n][m-1]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n][m-1]=='0'&&s[n-1][m]=='0'){
		ans.push_back((node){n-1,m-1,n-1,m,n,m});
		s[n-1][m-1]^=1,s[n-1][m]^=1,s[n][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m-1]=='0'){
		ans.push_back((node){n-1,m-1,n,m,n,m-1});
		s[n-1][m-1]^=1,s[n][m]^=1,s[n][m-1]^=1; 
		calc();
		return;
	}
	if(s[n][m]=='0'){
		ans.push_back((node){n-1,m-1,n,m,n,m-1});
		s[n-1][m-1]^=1,s[n][m]^=1,s[n][m-1]^=1; 
		calc();
		return;
	}
	if(s[n][m-1]=='0'){
		ans.push_back((node){n,m-1,n,m,n-1,m});
		s[n][m-1]^=1,s[n][m]^=1,s[n-1][m]^=1; 
		calc();
		return;
	}
	if(s[n-1][m]=='0'){
		ans.push_back((node){n-1,m,n,m,n,m-1});
		s[n-1][m]^=1,s[n][m]^=1,s[n][m-1]^=1; 
		calc();
		return;
	} 
}
inline void print(){
	for(re int i=1;i<=n;++i,puts(""))for(re int j=1;j<=m;++j)putchar(s[i][j]^1);
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans.clear();
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j)s[i][j]^=1;
		for(re int i=1;i<=n-2;++i){
			for(re int j=1;j<=m;++j){
				if(s[i][j]=='0'){
					if(j!=m)
					ans.push_back((node){i,j,i+1,j,i+1,j+1}),s[i][j]^=1,s[i+1][j]^=1,s[i+1][j+1]^=1;
					else 
					ans.push_back((node){i,j,i+1,j,i+1,j-1}),s[i][j]^=1,s[i+1][j]^=1,s[i+1][j-1]^=1;
				}
			}
		}
		re int i=n-1;
		for(re int j=1;j<=m-2;++j){
			if(s[i][j]=='0'&&s[i+1][j]=='0')ans.push_back((node){i,j,i+1,j,i+1,j+1}),s[i][j]^=1,s[i+1][j]^=1,s[i+1][j+1]^=1;
			else if(s[i][j]=='0'&&s[i+1][j]=='1')ans.push_back((node){i,j,i,j+1,i+1,j+1}),s[i][j]^=1,s[i][j+1]^=1,s[i+1][j+1]^=1;
			else if(s[i][j]=='1'&&s[i+1][j]=='0')ans.push_back((node){i+1,j,i,j+1,i+1,j+1}),s[i+1][j]^=1,s[i][j+1]^=1,s[i+1][j+1]^=1;
		}
		calc();
		printf("%d\n",ans.size());
		for(re int i=0;i<ans.size();++i)printf("%d %d %d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d,ans[i].e,ans[i].f);
		//	print();
		
	}
}