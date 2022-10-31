#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int ans[N];
void solve(const std::vector<int> &pos,const std::vector<int> &val,int dep){
	if(SZ(pos)==1)return ans[pos[0]]=val[0],void();
	std::vector<int> p0,p1,v0,v1;
	for(auto x:pos)(x>>dep&1?p1:p0).pb(x);
	for(auto x:val)(x>>dep&1?v1:v0).pb(x);
	if(SZ(p0)!=SZ(v1)){
		if(SZ(v1)<SZ(v0))v1.pb(v0.back()),v0.pop_back();
		else v0.pb(v1.back()),v1.pop_back();
	}
	solve(p0,v1,dep+1),solve(p1,v0,dep+1);
}
void solve1(int n){
	if(n%2)return puts("NO"),void();
	std::vector<int> v(n);std::iota(v.begin(),v.end(),1);
	solve(v,v,0);puts("YES");for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
}
void get(const std::vector<int> &p){
	std::vector<int> v(p);
	for(int i=0;i+1<SZ(v);i+=2)std::swap(v[i],v[i+1]);
	if(SZ(p)%2)std::swap(v[SZ(v)-1],v[0]);
	for(int i=0;i<SZ(p);++i)ans[p[i]]=v[i];
}
void solve2(int n){
	if(n<=5||!(n&(n-1)))return puts("NO"),void();
	if(n==6)return puts("YES\n3 6 2 5 1 4"),void();
	int p=3;while(p*2+1<=n)p=p*2+1;
	for(int i=p,q=n;i>=7;q=i,i/=2){
		std::vector<int> v;for(int j=i+1;j<=q;++j)v.pb(j);
		get(v);
	}
	ans[1]=3,ans[2]=7,ans[3]=1,ans[4]=5,ans[5]=4,ans[6]=2,ans[7]=6;
	puts("YES");for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){
	int n;read(n);
	solve1(n),solve2(n);
	return 0;
}