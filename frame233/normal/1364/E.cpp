#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int n,ans[2049];std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int ask(int i,int j){
	printf("? %d %d\n",i,j),fflush(stdout);
	int x;read(x);return x;
}
int get(int x,int v){
	std::vector<int> p;for(int i=1;i<=n;++i)if(i!=x)p.pb(i);
	std::shuffle(p.begin(),p.end(),rnd);if(SZ(p)>15)p.resize(15);
	int ans=v;for(int i=0;i<SZ(p);++i)ans&=ask(x,p[i]);
	return ans;
}
int main(){
	read(n);
	std::vector<int> p(n);std::iota(p.begin(),p.end(),1),std::shuffle(p.begin(),p.end(),rnd);
	int cur=p[0],val=get(p[0],2047);
	for(int i=1;i<n;++i){
		int tmp=ask(cur,p[i]);
		if(tmp==val)cur=p[i],val=get(p[i],tmp);
	}
	for(int i=1;i<=n;++i)ans[i]=i==cur?0:ask(cur,i);
	printf("! ");for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	fflush(stdout);
	return 0;
}