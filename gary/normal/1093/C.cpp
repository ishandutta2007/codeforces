//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL b[200000+10];
stack<LL> num;
int main(){
	LL fir=-INF,sec=INF;
	int n;
	scanf("%d",&n);
	rb(i,1,(n>>1)){
		scanf("%I64d",&b[i]);
	}
	fir=0;
	printf("0 "); 
	sec=b[1];
	num.push(b[1]);
	rb(i,2,(n>>1)){
		if(b[i]<=sec){
			fir=fir;
			sec=b[i]-fir;
		}
		else{
			fir=max(fir,b[i]-sec);
			sec=b[i]-fir;
		}
		printf("%I64d ",fir);
		num.push(sec);
	}
	rb(i,1,(n>>1)){
		printf("%I64d ",num.top());
		num.pop();
	}
	return 0;
}