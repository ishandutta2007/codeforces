#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;std::vector<std::pair<int,int>> ans;
int a[N];inline bool cmp(int x,int y){return a[x]<a[y];}
inline void apply(int x,int y){a[y]-=a[x],a[x]*=2,ans.pb({x,y});}
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	int cnt=0;for(int i=1;i<=n;++i)cnt+=!!a[i];
	if(cnt<2)return puts("-1"),0;
	while(true){
		std::vector<int> v;
		for(int i=1;i<=n;++i)if(a[i]&&SZ(v)<3)v.pb(i);
		if(SZ(v)<3)break;
		std::sort(v.begin(),v.end(),cmp);
		while(a[v[0]]){
			int t=a[v[1]]/a[v[0]];
			while(t){
				if(t&1)apply(v[0],v[1]);
				else apply(v[0],v[2]);
				t>>=1;
			}
			std::sort(v.begin(),v.end(),cmp);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
	return 0;
}