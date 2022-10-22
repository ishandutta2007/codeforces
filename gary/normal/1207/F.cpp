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
LL res[201][200];
LL line[500000+10];
int main(){
	int q;
	cin>>q;
	while(q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int A,B;
			scanf("%d %d",&A,&B);
			rb(i,1,200) res[i][A%i]+=B;
			line[A]+=B;
		}
		else{
			int A,B;
			scanf("%d %d",&A,&B);
			if(A<=200) printf("%I64d\n",res[A][B]);
			else{
				LL RES=0;
				for(int i=B;i<=500000;i+=A){
					RES+=line[i];
				}
				printf("%I64d\n",RES);
			}
		}
	}
	return 0;
}