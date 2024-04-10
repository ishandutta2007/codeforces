#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
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
int T,n;
int a[N],b[N],an,bn;
bool zero;
int main(){
	T=read();
	while(T--){
		n=read();
		an=bn=0;
		zero=false;
		for(int i=1;i<=n;++i){
			int x=read();
			if(!x){
				zero=true;
				continue;
			}
			if(x>0)a[++an]=x;
			else b[++bn]=-x;
		}
		sort(a+1,a+an+1,greater<int>());
		sort(b+1,b+bn+1,greater<int>());
		ll ans=zero?0:-4e18;
		if(!an){
			if(!zero){
				ans=-1;
				for(int i=bn;i>=bn-4;--i){
					ans*=b[i];
				}
			}
		}
		else{
			for(int i=1;i<=5;++i){
				if(an<i||bn<5-i)continue;
				ll tmp=1;
				for(int j=1;j<=i;++j){
					tmp*=a[j];
				}
				for(int j=1;j<=5-i;++j){
					tmp*=b[j];
				}
				ans=max(ans,i&1?tmp:-tmp);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}