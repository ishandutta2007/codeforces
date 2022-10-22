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
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	int res=-1;
	rb(i,1,n){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		if(xi>s) continue;
		if(xi==s){
			if(yi>0) continue;
			res=max(res,0);
			continue;
		}
		if(yi==0) yi=100;
		res=max(res,100-yi);
	}
	cout<<res<<endl;
	return 0;
}