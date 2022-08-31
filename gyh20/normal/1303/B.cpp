#include<cstdio>
#include<cstring>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,t,fst,lst,ans,a,b,c,l,r;
char s[100002];
inline int check(re int x){
	int tmp=x/(b+c);
	int k=tmp*b,k1=tmp*c;
	int tmp1=x-(b+c)*tmp;
	
	if(tmp1>b)k+=b,k1+=tmp1-b;
	else k+=tmp1;
	if(k1>a/2)k1=a/2;
	return k+k1;
}
signed main(){
	int t=read();
	while(t--){
	a=read();
	b=read();
	c=read();
	if(c<=b)printf("%lld\n",a);
	else{
		l=a;
		r=2e18;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)>=a)r=mid,ans=mid;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
		}
}