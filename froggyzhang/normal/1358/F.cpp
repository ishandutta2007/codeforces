#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
typedef long long ll;
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
int n;
ll a[N],b[N];
int ans[N<<7];
int tot;
long long mn;
vector<pair<int,long long> > qwq;
bool check(){
	for(int i=1;i<=n;++i)if(a[i]^b[i])return false;
	return true;
}
bool _gcd(ll x,ll y){
	if(!x||!y)return false;
	if(y==a[2]||y==a[1]){
		qwq.push_back(make_pair(1,1)),swap(x,y);
	}
	if(x==a[2]){
		swap(a[1],a[2]);
		if((y-a[2])%x)return false;
		qwq.push_back(make_pair(0,(y-a[2])/x));
		qwq.push_back(make_pair(1,1));
		return true;
	}
	if(x==a[1]){
		if((y-a[2])%x)return false;
		qwq.push_back(make_pair(0,(y-a[2])/x));
		return true;
	}
	qwq.push_back(make_pair(1,1));
	qwq.push_back(make_pair(0,x/y));
	return _gcd(y,x%y);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	if(n==1){
		if(a[1]==b[1])printf("SMALL\n0\n");
		else printf("IMPOSSIBLE\n");
		return 0;
	}
	if(n==2){
		if(!_gcd(b[1],b[2])){
			printf("IMPOSSIBLE\n");
			return 0;
		}
		long long mn=0;
		for(auto x:qwq){
			if(!x.first)mn+=x.second;
			tot+=x.second;
		}
		if(mn>200000){
			printf("BIG\n%lld\n",mn);
			return 0;
		}
		printf("SMALL\n%d\n",tot);
		for(int i=(int)qwq.size()-1;i>=0;--i){
			int t=qwq[i].second;
			while(t--)putchar(qwq[i].first?'R':'P');
		}
		return 0;
	}
	while(!check()){
		reverse(b+1,b+n+1),ans[++tot]=1;
		if(check())break;
		if(b[1]>b[n])reverse(b+1,b+n+1),--tot;
		for(int i=n;i>=2;--i){
			b[i]-=b[i-1];
			if(b[i]<=0){
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
		ans[++tot]=0,++mn;
	}
	if(mn>200000){
		printf("BIG\n%lld\n",mn);
		return 0;
	}
	printf("SMALL\n%d\n",tot);
	while(tot)putchar(ans[tot--]?'R':'P');
	return 0;
}