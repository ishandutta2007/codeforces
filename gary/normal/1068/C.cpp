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
vector<int> each[101];
int tot[101]={0};
int to_this[101]={0};
int las=0;
int main(){
	int n,m;
	//<=100 <=1000
	scanf("%d %d",&n,&m);
	rb(i,1,m){
		int xi,yi;
		scanf("%d %d",&xi,&yi);
		if(xi<yi)  swap(xi,yi);
		each[xi].PB(yi);
		to_this[yi]++;
	}
	rb(i,1,n){
		int SZ=each[i].size();
		printf("%d\n",SZ+1+to_this[i]);
		tot[i]=las+1;
		rb(j,1,to_this[i]+1)
		printf("%d %d\n",i,++las);
		rep(j,SZ){
			printf("%d %d\n",i,tot[each[i][j]]++);
		}
	}
	return 0;
}