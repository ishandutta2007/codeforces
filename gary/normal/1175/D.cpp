//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL a[300000+10];
pair<LL,LL> sum[300000+10];
int main(){
	LL n,k;
	scanf("%I64d %I64d",&n,&k);
	rb(i,1,n) scanf("%I64d",&a[i]),sum[i].FIR=sum[i-1].FIR+a[i],sum[i].SEC=i;;
	LL res=sum[n].FIR*k;
	int tot=0;
	sort(sum+1,sum+1+n);
	rb(i,1,n){
		if(tot==k-1) break;
		if(sum[i].SEC==n) continue;
		tot++;
		res-=sum[i].FIR;
	}
	printf("%I64d\n",res);
	return 0;
}