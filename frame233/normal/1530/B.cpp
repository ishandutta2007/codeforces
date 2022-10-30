#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=25;
typedef std::pair<int,int> pi;
int a[N][N],b[N][N];
int main(){
	int _;read(_);
	while(_--){
		int n,m;read(n,m);
		std::vector<pi> all;
		for(int i=2;i<=m;++i)all.pb({1,i});
		for(int i=2;i<=n;++i)all.pb({i,m});
		for(int i=m-1;i>=1;--i)all.pb({n,i});
		for(int i=n-1;i>1;--i)all.pb({i,1});
		for(int st=0;st<2;++st){
			memset(a,0,sizeof(a));
			a[1][1]=st;
			for(auto [x,y]:all){
				bool flag=0;
				for(int dx=-1;dx<=1;++dx)for(int dy=-1;dy<=1;++dy)if(a[x+dx][y+dy])flag=1;
				if(!flag)a[x][y]=1;
			}
			if(st==0)memcpy(b,a,sizeof(a));
		}
		int A=0;for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)A+=a[i][j];
		int B=0;for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)B+=b[i][j];
		if(A<B)memcpy(a,b,sizeof(a));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)printf("%d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}