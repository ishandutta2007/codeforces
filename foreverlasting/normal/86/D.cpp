//2018.10.22 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
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
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=2e5+10;
const int P=1e6+10;
namespace MAIN{
	int n,t;
	int a[N];
	int block;
	struct Q{
		int l,r,part,id;
		Q() {}
		Q(res l,res r,res id):l(l),r(r),part((l-1)/block+1),id(id) {}
		inline bool operator < (const Q &b) const {
			return part!=b.part?part<b.part:r>b.r;
		}
	}q[N];
	LL ans[N];
	LL ret;
	int cnt[P];
	inline void add(const res &x){
		ret+=1LL*2*cnt[x]*x+x,cnt[x]++;
	}
	inline void rem(const res &x){
		ret+=-1LL*2*cnt[x]*x+x,cnt[x]--;
	}
	inline void MAIN(){
		n=read(),t=read();
		block=sqrt(n);
		for(res i=1;i<=n;i++)a[i]=read();
		for(res i=1;i<=t;i++){
			res l=read(),r=read();
			q[i]=Q(l,r,i);
		}
		sort(q+1,q+t+1);
		res l=1,r=0;
		for(res i=1;i<=t;i++){
			while(l<q[i].l)add(a[l++]);
			while(l>q[i].l)rem(a[--l]);
			while(r<q[i].r)rem(a[++r]);
			while(r>q[i].r)add(a[r--]);
			ans[q[i].id]=ret;
		}
		for(res i=1;i<=t;i++)printf("%lld\n",ans[i]);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}