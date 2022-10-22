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
int main(){
	LL n,m,k;
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	k++;
	if(k<=n){
		printf("%I64d 1",k);
		return 0;
	}
	k-=n;
	LL wise=m-1;
	LL block=k/(LL)(wise*2)+bool(k%(LL)(wise*2));
	LL row=(block-1)*2;
	LL mod=k%(LL)(wise+wise);
	if(mod==0) mod=wise+wise;
	if(mod<=wise){
		row+=1;
		cout<<n-row+1<<" ";
		cout<<1+mod<<endl;
	}
	else{
		row+=2;
		cout<<n-row+1<<" ";
//		cout<<mod<<endl;
		mod-=wise;
//		cout<<mod<<endl;
		cout<<m-mod+1;
	}
	return 0;
}