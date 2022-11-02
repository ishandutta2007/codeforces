#include <bits/stdc++.h>
using namespace std;
const int MX=1000005;
typedef long long LL;
struct data{
	LL sum,suf;
	void init(){
		sum=suf=0ll;
	}
};
data merge(data A,data B){
	data ret;
	ret.init();
	ret.sum=A.sum+B.sum;
	ret.suf=max(B.suf,A.suf+B.sum);
	return ret;
}
namespace segT{
	data a[MX*4+5];
	void init(int p,int l=0,int r=MX){
		if(l==r){
			a[p].sum=-1ll;
			a[p].suf=0ll;
		}
		else{
			int M=((l+r)>>1);
			init((p<<1),l,M);
			init((p<<1|1),M+1,r);
			a[p]=merge(a[p<<1],a[p<<1|1]);
		}
	}
	void modify(int p,int d,int v,int l=0,int r=MX){
		if(l==r){
			a[p].sum+=(LL)v;
			a[p].suf=max(0ll,a[p].sum);
		}
		else{
			int M=((l+r)>>1);
			if(d<=M)
				modify((p<<1),d,v,l,M);
			else
				modify((p<<1|1),d,v,M+1,r);
			a[p]=merge(a[p<<1],a[p<<1|1]);
		}
	}
	data qry(int p,int L,int R,int l=0,int r=MX){
		if(l>=L && r<=R) return a[p];
		int M=((l+r)>>1);
		data ret;
		ret.init();
		if(L<=M) ret=qry((p<<1),L,R,l,M);
		if(R>M) ret=merge(ret,qry((p<<1|1),L,R,M+1,r));
		return ret;
	}
};
int q,t[300005],d[300005];
char readch(){
	char c=getchar();
	while(c==' '|| c=='\n') c=getchar();
	return c;
}
int main(){
	int i,j,k;
	scanf("%d",&q);
	segT::init(1);
	for(i=0;i<q;++i){
		char c=readch();
		scanf("%d",t+i);
		if(c=='+'){
			scanf("%d",d+i);
			segT::modify(1,t[i],d[i]);
		}
		else if(c=='-'){
			segT::modify(1,t[t[i]-1],-d[t[i]-1]);
		}
		else{
			segT::modify(1,t[i],1);
			printf("%I64d\n",segT::qry(1,0,t[i]).suf);
			segT::modify(1,t[i],-1);
		}
	}
	return 0;
}