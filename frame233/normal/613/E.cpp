#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}
const int N=2005,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
char s[2][N],t[N];
int f[2][N][N],g[2][N][N];
int g0[2][N][N],g1[2][N][N];
int f0[2][N][N],f1[2][N][N];
int main(){
	int n=read_str(s[0]+1);
	read_str(s[1]+1);
	int m=read_str(t);
	if(m==1){
		int ans=0;
		for(int i=0;i<2;++i)for(int j=1;j<=n;++j)ans+=s[i][j]==t[0];
		printf("%d\n",ans);
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<2;++i)for(int j=1;j<n;++j)ans+=s[i][j]==t[0]&&s[i][j+1]==t[1];
		for(int i=0;i<2;++i)for(int j=2;j<=n;++j)ans+=s[i][j]==t[0]&&s[i][j-1]==t[1];
		for(int i=0;i<2;++i)for(int j=1;j<=n;++j)ans+=s[i][j]==t[0]&&s[!i][j]==t[1];
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0;i<2;++i)for(int j=1;j<=n;++j){
		for(int k=0;k<m;++k)if(s[i][j]==t[k]){
			g0[i][j][k]=g0[i][j-1][k+1]+1;
			g1[i][j][k]=(k?g1[i][j-1][k-1]:0)+1;
		}
	}
	for(int i=0;i<2;++i)for(int j=n;j>=1;--j){
		for(int k=0;k<m;++k)if(s[i][j]==t[k]){
			f0[i][j][k]=f0[i][j+1][k+1]+1;
			f1[i][j][k]=(k?f1[i][j+1][k-1]:0)+1;
		}
	}
	for(int i=0;i<2;++i)for(int j=0;j<=n+1;++j)f[i][j][m]=1,g[i][j][m]=1;
	for(int j=1;j<=n;++j)for(int i=0;i<2;++i){
		for(int k=0;k<m;++k)if(s[i][j]==t[k]){
			add(g[i][j][k],g[i][j-1][k+1]);
			int tar=m-k;
			if(tar>2&&tar%2==0&&g1[i^1][j][m-1]>=tar/2&&g0[i][j][k]>=tar/2)add(g[i][j][k],1);
			if(s[!i][j]==t[k+1])add(g[i][j][k],g[!i][j-1][k+2]);
		}
	}
	for(int j=n;j>=1;--j)for(int i=0;i<2;++i){
		for(int k=0;k<m;++k)if(s[i][j]==t[k]){
			add(f[i][j][k],f[i][j+1][k+1]);
			int tar=m-k;
			if(tar>2&&tar%2==0&&f1[i^1][j][m-1]>=tar/2&&f0[i][j][k]>=tar/2)add(f[i][j][k],1);
			if(s[!i][j]==t[k+1])add(f[i][j][k],f[!i][j+1][k+2]);
		}
	}
	int ans=0;
	for(int i=0;i<2;++i)for(int j=1;j<=n;++j)if(s[i][j]==t[0]){
		add(ans,f[i][j+1][1]),add(ans,g[i][j-1][1]);
		for(int k=0;k<m;++k){
			if(s[i][j+k]!=t[k])break;
			if(g0[!i][j+k][k+1]>=k+1)add(ans,g[!i][j-1][k+k+2]);
		}
		for(int k=0;k<m&&k<j;++k){
			if(s[i][j-k]!=t[k])break;
			if(f0[!i][j-k][k+1]>=k+1)add(ans,f[!i][j+1][k+k+2]);
		}
	}
	printf("%d\n",ans);
	return 0;
}