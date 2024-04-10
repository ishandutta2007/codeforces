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
int boss[500000+10];
int tot[500000+10];
int find_(int now){
	if(boss[now]==now) return now;
	return boss[now]=find_(boss[now]); 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rb(i,1,n) boss[i]=i,tot[i]=1;
	rb(i,1,m){
		int ki;
		scanf("%d",&ki);
		int all_boss;
		int ai;
		rb(j,1,ki){
			scanf("%d",&ai);
			if(j==1){
				all_boss=find_(ai);
			}
			else{
				if(all_boss!=find_(ai)){
					tot[all_boss]+=tot[find_(ai)];
					boss[find_(ai)]=all_boss;
				}
			}
		}
	}
	rb(i,1,n){
		printf("%d ",tot[find_(i)]);
	}
	return 0;
}