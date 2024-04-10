#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
int n;ll a[N],b[N];
void force(){
	string res;int cnt=0;
	for(;;){
		bool fl1=1,fl2=1;
		rep(i,1,n){
			if(b[i]!=a[i])fl1=0;
			if(b[i]!=a[n-i+1])fl2=0;
			if(b[i]<a[i]&&b[i]<a[n-i+1]){
				printf("IMPOSSIBLE\n");exit(0);
			}
		}
		if(fl2){
			res+="R";fl1=1;
		}
		if(fl1){
			if(cnt<=200000){
				printf("SMALL\n%d\n",(int)res.length());
				reverse(res.begin(),res.end());
				printf("%s\n",res.c_str());
			}else printf("BIG\n%d\n",cnt);
			exit(0);
		}
		++cnt;
		if(b[1]>b[n]){res+="R";
			rep(i,1,n/2)swap(b[i],b[n-i+1]);
		}
		res+="P";dep(i,n,1)b[i]-=b[i-1];
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)scanf("%lld",&b[i]);
	if(n==1){
		if(a[1]==b[1])printf("SMALL\n0\n\n");
		else printf("IMPOSSIBLE\n");return 0;
	}
	if(n>2)force();
	ll a1=a[1],a2=a[2],b1=b[1],b2=b[2],cnt=0;
	if(a1>a2)swap(a1,a2);
	for(;;){
		if(b1>b2)swap(b1,b2);
		if(a1==b1&&a2==b2)break;
		if(b1<a1||b2<a2){
			printf("IMPOSSIBLE\n");return 0;
		}
		ll t=((a1==b1&&!((b2-a2)%b1))?b2-a2:b2)/b1;
		cnt+=t;b2-=b1*t;
	}
	if(cnt<=200000)force();
	printf("BIG\n%lld\n",cnt);
}