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
int pos[200000+10];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		int fi;
		scanf("%d",&fi);
		pos[fi]=i;
	}
	LL res=0;
	rb(i,2,n){
		res+=abs(pos[i]-pos[i-1]);
	}
	printf("%I64d\n",res);
	return 0;
}//