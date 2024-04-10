#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;
typedef std::pair<int,int> pi;
int d[N],col[N],cnt[2],n;
void ask(int x){
	printf("? %d\n",x),fflush(stdout);
	for(int i=1;i<=n;++i)read(d[i]);
}
int main(){
	read(n);
	std::vector<pi> E;
	ask(1);
	for(int i=1;i<=n;++i)col[i]=d[i]&1,++cnt[col[i]];
	--cnt[0];
	int tar=cnt[0]<cnt[1]?0:1;
	if(tar==0)for(int i=1;i<=n;++i)if(d[i]==1)E.pb({1,i});
	for(int i=2;i<=n;++i)if(col[i]==tar){
		ask(i);
		for(int j=1;j<=n;++j)if(d[j]==1)E.pb({i,j});
	}
	printf("!\n");
	for(auto [x,y]:E)printf("%d %d\n",x,y);
	fflush(stdout);
	return 0;
}