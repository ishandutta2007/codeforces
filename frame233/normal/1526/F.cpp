#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef std::pair<int,int> pi;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int ask(int a,int b,int c){
	printf("? %d %d %d\n",a,b,c),fflush(stdout);
	int x;read(x);return x;
}
int ans[100005];
void MAIN(){
	int n;read(n);
	int mn=1e9,a=0,b=0,c=0;
	for(int i=1;i<=420;++i){
		int x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
		while(x==y||y==z||x==z)x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
		int tp=ask(x,y,z);
		if(tp<mn)mn=tp,a=x,b=y,c=z;
	}
	std::vector<pi> v;
	for(int i=1;i<=n;++i)if(i!=a&&i!=b)v.pb({ask(i,a,b),i});
	std::sort(v.begin(),v.end(),std::greater<pi>());
	int x=v[0].second,y;
	while(v[1].first==v[0].first)v.erase(v.begin()+1);
	if(v[1].first>v[2].first)y=v[1].second;
	else y=v[ask(x,v[1].second,a)<ask(x,v[2].second,a)?1:2].second;
	ans[x]=1,ans[y]=2;
	for(int i=1;i<=n;++i)if(i!=x&&i!=y)ans[i]=ask(x,y,i)+2;
	if(ans[1]>ans[2])for(int i=1;i<=n;++i)ans[i]=n-ans[i]+1;
	printf("! ");for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	fflush(stdout);
	read(x);assert(x==1);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}