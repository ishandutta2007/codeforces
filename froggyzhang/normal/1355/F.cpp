#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
const ll inf=1e18;
const int MAX=1e9;
const int B=617;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
//#define mak akioi
int n;
int ntp[N],T;
ll t[N];
vector<ll> all;
inline int Ask(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	#ifdef mak
	return __gcd(x,1LL*n);
	#endif
	return read();
}
inline void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);
}
void Solve(){
	#ifdef mak
	n=read();
	#endif
	int tot=1;
	for(auto x:all){
		tot*=Ask(x);	
	}
	static vector<int> vec;
	vec.clear();
	for(int i=2;i<=617;++i){
		if(!ntp[i]&&tot%i==0){
			vec.push_back(i);
		}
	}
	if(vec.size()%2)vec.push_back(1);
	int ans=1;
	for(int i=0;i<(int)vec.size();i+=2){
		int x=vec[i],y=vec[i+1];
		int num=Ask(t[x]*t[y]);
		int sx=1,sy=1;
		while(num%x==0)++sx,num/=x;
		if(y>1)while(num%y==0)++sy,num/=y;
		ans*=sx*sy;
	}
	Report(max(8,ans<<1));
}
int main(){
	ntp[1]=1;
	ll now=1;
	t[1]=1;
	for(int i=2;i<=B;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=B;j+=i){
				ntp[j]=1;
			}
			t[i]=i;
			while(1LL*t[i]*i<=MAX)t[i]*=i;
			if(now<inf/i)now*=i;
			else all.push_back(now),now=1;
		}
	}
	all.push_back(now);
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}