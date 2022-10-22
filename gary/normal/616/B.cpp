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
int mini[101];
int main(){
	int res=-INF;
	memset(mini,0x3f,sizeof(mini));
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		rb(j,1,m){
			int ai;
			scanf("%d",&ai);
			mini[i]=min(mini[i],ai);
		} 
		res=max(res,mini[i]);
	} 
	printf("%d\n",res);
	return 0;
}