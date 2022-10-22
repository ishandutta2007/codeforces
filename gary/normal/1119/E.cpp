//LUOGU BOTE
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int a[300000+10];
LL final=0;
LL ret=0;
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		LL cost=ret;
		if(a[i]/2>ret){
			a[i]-=ret*2;
			final+=ret;
			ret=0;
			final+=a[i]/3;
			a[i]%=3;
			ret+=a[i];
		}
		else{
			final+=a[i]/2;
			ret-=a[i]/2;
			ret+=a[i]&1;
		}
	}
	printf("%I64d\n",final);
	return 0;
}