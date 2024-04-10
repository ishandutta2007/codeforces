//2018.10.25 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL N=1e5+10;
namespace MAIN{
	LL n;
	LL a[N];
#define lowbit(x) (x&-x)
	struct BIT{
		LL tr[N];
		inline void modify(const res &x,const res &y){
			for(res i=x;i<=n;i+=lowbit(i))tr[i]+=y;
		}
		inline LL query(const res &x){
			res ret=0;
			for(res i=x;i;i-=lowbit(i))ret+=tr[i];
			return ret;
		}
	}T1,T2;
#define lb double
	lb ans;
	inline void MAIN(){
		n=read();
		for(res i=1;i<=n;i++)a[i]=read(),ans+=1.0*i*(n-i)*(n-i+1)/2.0/n/(n+1);
		for(res i=n;i;i--){
			res x=T1.query(a[i]-1);
			ans-=1.0*x*(i*2.0+n*i*2.0-n*(n+1))*1.0/n/(n+1);
			x=T2.query(a[i]-1);
			ans+=1.0*i*x*2.0/n/(n+1);
			T1.modify(a[i],1),T2.modify(a[i],i);
		}
		printf("%.9lf\n",ans);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}