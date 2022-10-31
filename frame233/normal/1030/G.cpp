#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2000005,MAXN=200005,mod=1000000007;typedef std::pair<int,int> pi;
bool pr[N];int p[N/10],md[N],pos,a[MAXN],fir[N],sec[N];
void sieve(){
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,md[i]=i;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1,md[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
std::vector<pi> get(int x){
	std::vector<pi> ans;
	while(x>1){
		if(!ans.empty()&&md[x]==ans.back().first)++ans.back().second;
		else ans.pb({md[x],1});
		x/=md[x];
	}
	return ans;
}
std::vector<pi> d[N];bool mark[N];
int main(){
	sieve();int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	std::sort(a+1,a+n+1,std::greater<int>());
	for(int i=1;i<=n;++i){
		if(!fir[a[i]])fir[a[i]]=1;
		else{
			mark[i]=1;std::vector<pi> vec=get(a[i]-1);d[i]=vec;
			for(const auto &it:vec){
				if(it.second>fir[it.first])sec[it.first]=fir[it.first],fir[it.first]=it.second;
				else if(it.second>sec[it.first])sec[it.first]=it.second;
			}
		}
	}
	int ans=1;for(int i=1;i<N;++i)for(int j=0;j<fir[i];++j)ans=1LL*ans*i%mod;
	for(int i=1;i<=n;++i)if(mark[i]){
		bool tag=1;for(const auto &it:d[i])tag&=it.second<fir[it.first]||sec[it.first]==fir[it.first];
		if(tag){++ans;break;}
	}
	printf("%d\n",ans%mod);
	return 0;
}