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
int a[200000+10];
int b[105];int n,q,m;
pair<mp,int> sav[200000+10];
void dfs(int now,int NW){
	NW--;
	rl(i,NW,1){
		int ty,li,ri;
		ty=sav[i].FIR.FIR;
		li=sav[i].FIR.SEC;
		ri=sav[i].SEC;
		if(now<=ri&&now>=li){
			if(ty==1){
				int nex=now-1;
				if(nex==li-1){
					nex=ri;
				}
				dfs(nex,i);
			}
			else{
				int from_l=now-li+1;
				int nex=ri-from_l+1;
				dfs(nex,i);
			}
			return;
		}
	}
	printf("%d ",a[now]);
}
int main(){
	scanf("%d %d %d",&n,&q,&m);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,q){
//		operate();
		scanf("%d %d %d",&sav[i].FIR.FIR,&sav[i].FIR.SEC,&sav[i].SEC);
	}
	rb(i,1,m) scanf("%d",&b[i]);
	rb(i,1,m){
		dfs(b[i],q+1);
	}
	return 0;
}