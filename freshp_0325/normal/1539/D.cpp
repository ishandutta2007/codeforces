#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct object{
	LL a,b;
	object(){}
	object(LL A,LL B){a=A,b=B;}
	bool operator < (object ano) const {return b<ano.b;}
}ob[100005];
LL n;
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	scanf("%lld %lld",&ob[i].a,&ob[i].b);
	sort(ob+1,ob+1+n);
	LL pos=n,sum=0,ans=0;
	for(LL i=1;i<=pos;)
	{
		if(ob[i].b<=sum)	sum+=ob[i].a,ans+=ob[i].a,++i;
		else
		{
			LL st=min(ob[pos].a,ob[i].b-sum);
			sum+=st;
			ans+=st*2;
			ob[pos].a-=st;
			if(!ob[pos].a)	--pos;
		}
	}
	printf("%lld",ans);
	return 0;
}