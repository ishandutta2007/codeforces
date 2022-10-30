#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=50005;typedef long long ll;
int a[N],f[N][2][2];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int x;read(x);for(int i=1;i<=n;++i)a[i]-=x;
	if(n==1)return puts("1"),void();
	memset(f,0,sizeof(f));
	for(int x=0;x<2;++x)for(int y=0;y<2;++y)if(!x||!y||a[1]+a[2]>=0)f[2][x][y]=x+y;
	for(int i=2;i<n;++i){
		for(int x=0;x<2;++x)for(int y=0;y<2;++y){
			for(int z=0;z<2;++z){
				if(y&&z&&a[i]+a[i+1]<0)continue;
				if(x&&y&&z&&a[i-1]+a[i]+a[i+1]<0)continue;
				chmax(f[i+1][y][z],f[i][x][y]+z);
			}
		}
	}
	int ans=0;for(int x=0;x<2;++x)for(int y=0;y<2;++y)ans=std::max(ans,f[n][x][y]);
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}