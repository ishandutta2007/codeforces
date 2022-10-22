#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct cave{
	LL siz,val;
	cave(){}
	cave(LL S,LL V){siz=S,val=V;}
	bool operator < (cave ano) const {return val<ano.val || (val==ano.val && siz>ano.siz);}
}a[100005];
LL n;
void Solve()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)
	{
		LL siz;
		scanf("%lld",&siz);
		LL val=0;
		for(LL j=1;j<=siz;++j)
		{
			LL s;
			scanf("%lld",&s);
			val=max(val,s-j+2);
		}
		a[i]=cave(siz,val);
	}
	sort(a+1,a+1+n);
	LL ans=a[1].val,pos=a[1].val+a[1].siz;
	for(LL i=2;i<=n;++i)
	{
		if(pos>a[i].val)	pos+=a[i].siz;
		else	ans+=a[i].val-pos,pos=a[i].val+a[i].siz;
	}
	printf("%lld\n",ans);
}
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)	Solve();
	return 0;
}