#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;
char s[N][N];int d[N],n,a[N];
void flip(int x,int y){
	if(s[x][y]=='1')--d[x];else ++d[x];
	if(s[y][x]=='1')--d[y];else ++d[y];
	s[x][y]^=1,s[y][x]^=1;
}
void flip(int x){for(int i=1;i<=n;++i)if(i!=x)flip(x,i);}
bool check(){
	memcpy(a,d,(n+2)<<2),std::sort(a+1,a+n+1);
	for(int i=1,s=0;i<n;++i){s+=a[i];if(s==i*(i-1)/2)return 0;}
	return 1;
}
int main(){
	read(n);for(int i=1;i<=n;++i)scanf("%s",s[i]+1),d[i]=std::count(s[i]+1,s[i]+n+1,'1');
	if(check())return puts("0 1"),0;
	if(n<=6){
		int mn=1e9,ans=0;
		for(int st=0;st<1<<n;++st){
			for(int i=0;i<n;++i)if(st>>i&1)flip(i+1);
			if(check()){
				int tmp=__builtin_popcount(st);
				if(tmp<mn)mn=tmp,ans=1;else if(tmp==mn)++ans;
			}
			for(int i=0;i<n;++i)if(st>>i&1)flip(i+1);
		}
		if(mn>=1e9)puts("-1");
		else{
			for(int i=1;i<=mn;++i)ans*=i;
			printf("%d %d\n",mn,ans);
		}
	}
	else{
		int ans=0;for(int i=1;i<=n;++i)flip(i),ans+=check(),flip(i);
		printf("1 %d\n",ans);
	}
	return 0;
}