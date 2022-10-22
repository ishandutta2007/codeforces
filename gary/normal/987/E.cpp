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
int pos[1000000+10];
int fan[1000000+10];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		pos[ai]=i;
		fan[i]=ai;
	}
	LL tot=0;
	rb(i,1,n){
		if(pos[i]!=i)tot+=1;
		fan[pos[i]]=fan[i];
		pos[fan[i]]=pos[i];
	}
	if((tot&1)==1){
		if((n&1)==1){
			puts("Petr");
		}
		else{
			puts("Um_nik");
		}
	} 
	else{
		if((n&1)==0){
			puts("Petr");
		}
		else{
			puts("Um_nik");
		}
	}
	return 0;
}