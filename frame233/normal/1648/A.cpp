#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
std::vector<int> v1[N],v2[N];ll ans;
void solve(std::vector<int> v){
	std::sort(v.begin(),v.end());
	ll sum=0;int c=0;
	for(auto it:v)sum+=it,++c,ans+=1LL*c*it-sum;
}
int main(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i){
		for(int j=1,x;j<=m;++j){
			read(x),v1[x].pb(i),v2[x].pb(j);
		}
	}
	for(int i=1;i<=1e5;++i)solve(v1[i]);
	for(int i=1;i<=1e5;++i)solve(v2[i]);
	printf("%lld\n",ans);
	return 0;
}