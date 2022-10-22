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
int res=0;
int print[10]={6,2,5,5,4,5,6,3,7,6};
inline void calc(int x){
	while(x){
		res+=print[x%10];
		x/=10;
	}
}
int main(){
	int a,b;
	//a<=1e6,b<=1e6
	scanf("%d %d",&a,&b);
	rb(i,a,b){
		calc(i);
	}
	printf("%d\n",res);
	return 0;
}