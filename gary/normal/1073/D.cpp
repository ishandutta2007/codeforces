//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
#define niv vector<LL>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const LL INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL n,t;
LL a[200000+10];
LL cost;
LL _count=0;
LL get(LL tmpt){
	rb(i,1,n){
		if(a[i]<=tmpt){
			tmpt-=a[i];
			cost+=a[i];
			_count++;
		}
	}
	return cost;
}
int main(){
	scanf("%I64d %I64d",&n,&t);
	rb(i,1,n){
		scanf("%I64d",&a[i]);
	}
	LL res=0;
	while(1){
		_count=0;
		cost=0;
		cost=get(t);
		if(!cost) break;
		res+=(t/cost)*_count;
		t%=cost;
	}
	printf("%I64d\n",res);
	return 0;
}