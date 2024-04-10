#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=100005,MAXN=1000005;typedef std::pair<int,int> pi;
int a[N],cnt[MAXN];bool mark[N];
std::vector<int> get(int x){
	std::vector<int> vec;
	for(int i=2;i*i<=x;++i)if(x%i==0){vec.pb(i);while(x%i==0)x/=i;}
	if(x>1)vec.pb(x);
	return vec;
}
int main(){
	int n;read(n);std::vector<pi> vec;
	for(int i=1;i<=n;++i){
		read(a[i]);int x=a[i],cur=0;
		while(x%2==0)x/=2,++cur;
		vec.pb({cur,i}),a[i]=x;
	}
	std::sort(vec.begin(),vec.end());
	int x1=vec[0].second,x2=vec[1].second;mark[x1]=mark[x2]=1;
	std::vector<int> v1=get(a[x1]),v2=get(a[x2]);
	for(auto it:v1)++cnt[it];
	for(auto it:v2)++cnt[it];
	for(int i=1;i<=1e6;++i)if(cnt[i]){
		std::vector<pi> vec;
		for(int j=1;j<=n;++j)if(j!=x1&&j!=x2){
			int x=a[j],cur=0;
			while(x%i==0)x/=i,++cur;
			vec.pb({cur,j});
		}
		std::sort(vec.begin(),vec.end());
		if(cnt[i]==2){for(int j=0;j<2&&j<SZ(vec);++j)mark[vec[j].second]=1;}
		else if(!vec.empty())mark[vec[0].second]=1;
	}
	std::vector<int> b;for(int i=1;i<=n;++i)if(mark[i])b.pb(i);
	std::vector<std::pair<int,std::vector<int>>> ans;
	for(int st=1;st<1<<SZ(b);++st){
		std::vector<int> cur;
		for(int i=0;i<SZ(b);++i)if(st>>i&1)cur.pb(b[i]);
		int c=__builtin_popcount(st);c=(c-2)*(c%2?-1:1);
		if(c>0)for(int i=0;i<c;++i)ans.pb({0,cur});
		else for(int i=0;i<-c;++i)ans.pb({1,cur});
	}
	printf("%d\n",SZ(ans));
	for(const auto &it:ans){
		printf("%d %d ",it.first,SZ(it.second));
		for(auto o:it.second)printf("%d ",o);
		printf("\n");
	}
	return 0;
}