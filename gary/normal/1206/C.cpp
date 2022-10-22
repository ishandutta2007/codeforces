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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int cycle[200000+10];
int main(){
	cin>>n;
	if((n&1)==0){
		puts("NO");
		return 0;
	}
	cycle[1]=1,cycle[1+n]=2;
	int color=0;
	int is=3;
	rb(i,1+n+1,n+n){
		if(!color){
			cycle[i]=is++;
			cycle[(i+n)%(n+n)]=is++;
		}
		else{
			cycle[(i+n)%(n+n)]=is++;
			cycle[i]=is++;
		}
		color^=1;
	}
	puts("YES");
	rb(i,1,n+n) printf("%d ",cycle[i]);
	return 0;
}