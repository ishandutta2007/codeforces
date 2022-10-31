#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=35;
int a[N][N],b[N][N];
int main(){
	int n;read(n);int m=(n+1)/2,ans=0;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)read(a[i][j]);
	for(int st=0;st<1<<m;++st){
		memcpy(b,a,sizeof(a));
		for(int i=0;i<m;++i)if(st>>i&1)for(int x=0;x<m;++x)for(int y=0;y<m;++y)b[m-1+x][i+y]*=-1;
		int tot=0;for(int i=0;i<n;++i)tot+=b[m-1][i];
		for(int i=0;i<m-1;++i){
			int cur=0;
			for(int t=0;t<2;++t){
				int sum=0;for(int j=0;j<m-1;++j)sum+=abs(b[i][j]+b[i][j+m]+b[i+m][j]+b[i+m][j+m]);
				cur=std::max(cur,sum+b[i][m-1]+b[i+m][m-1]);
				for(int j=0;j<m;++j)b[i][m-1+j]*=-1,b[m+i][m-1+j]*=-1;
			}
			tot+=cur;
		}
		ans=std::max(ans,tot);
		for(int i=0;i<m;++i)if(st>>i&1)for(int x=0;x<m;++x)for(int y=0;y<m;++y)b[m-1+x][i+y]*=-1;
	}
	printf("%d\n",ans);
	return 0;
}