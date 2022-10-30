#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;
std::vector<pi> v[N];int ans,n;
inline bool cmpx(const pi &a,const pi &b){return a.first<b.first;}
inline bool cmpy(const pi &a,const pi &b){return a.second<b.second;}
void calc1(const std::vector<int> &p){
	std::sort(v[p[0]].begin(),v[p[0]].end(),cmpx);
	std::sort(v[p[2]].begin(),v[p[2]].end(),cmpx);
	auto check=[&](int mid){
		int l=v[p[0]][mid-1].first,r=v[p[2]][SZ(v[p[2]])-mid].first;
		int cnt=0;for(auto [x,y]:v[p[1]])cnt+=l<x&&x<r;
		return cnt>=mid;
	};
	int l=0,r=n/3,mid;
	while(l<r)mid=(l+r+1)>>1,check(mid)?l=mid:r=mid-1;
	ans=std::max(ans,l);
}
void calc2(const std::vector<int> &p){
	std::sort(v[p[0]].begin(),v[p[0]].end(),cmpx);
	std::sort(v[p[1]].begin(),v[p[1]].end(),cmpx),std::reverse(v[p[1]].begin(),v[p[1]].end());
	std::sort(v[p[2]].begin(),v[p[2]].end(),cmpy);
	auto check=[&](int mid){
		int top=v[p[2]][SZ(v[p[2]])-mid].second,cnt,l=-1,r=-1;
		cnt=0;for(auto [x,y]:v[p[0]])if(y<top&&++cnt==mid){l=x;break;}
		cnt=0;for(auto [x,y]:v[p[1]])if(y<top&&++cnt==mid){r=x;break;}
		return l!=-1&&r!=-1&&l<r;
	};
	int l=0,r=n/3,mid;
	while(l<r)mid=(l+r+1)>>1,check(mid)?l=mid:r=mid-1;
	ans=std::max(ans,l);
}
void solve(){
	std::vector<int> p(3);std::iota(p.begin(),p.end(),0);
	do{calc1(p),calc2(p);}while(std::next_permutation(p.begin(),p.end()));
	for(int i=0;i<3;++i)for(auto &&it:v[i])it.second=1e9-it.second;
	std::iota(p.begin(),p.end(),0);
	do{calc2(p);}while(std::next_permutation(p.begin(),p.end()));
	for(int i=0;i<3;++i)for(auto &&it:v[i])it.second=1e9-it.second;
}
int main(){
	read(n);for(int i=1,x,y,z;i<=n;++i)read(x,y,z),--z,v[z].pb({x,y});
	solve();
	for(int i=0;i<3;++i)for(auto &&it:v[i])std::swap(it.first,it.second);
	solve();
	printf("%d\n",ans*3);
	return 0;
}