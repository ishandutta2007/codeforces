//LUOGU ROBOT
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
int n;
vector<int> each[300000+10];
map<int,int> each2 [300000+10];
LL sum[300000+10];
LL dp[300000+10];
map<int,int> last;
map<int,int> tmp;
map<int,int> ::IT ite;
LL data_st[2000000];
int L;
LL JIAN=0;
void dfs(int now,int Last){
	dp[now]=dp[Last];
	dp[now]+=sum[now];
	dp[now]-=JIAN;
//	cout<<now<<" "<<JIAN<<endl; 
	int SZ=each[now].size();
	for(ite=each2[now].begin();ite!=each2[now].end();ite++){
		data_st[L+ite->FIR]+=ite->SEC;
	} 	
	JIAN=data_st[L];
	L++;
	LL tmp_JIAN=JIAN;
	rb(i,1,SZ){
		JIAN=tmp_JIAN;
		if(each[now][i-1]==Last) continue;
		dfs(each[now][i-1],now);
	}
	L--;
	for(ite=each2[now].begin();ite!=each2[now].end();ite++){
		data_st[L+ite->FIR]-=ite->SEC;
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		each[x].PB(y);
		each[y].PB(x);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int vi,di,xi;
		scanf("%d %d %d",&vi,&di,&xi);
		if(di>=500000){
			di=500000;
		}
		sum[vi]+=xi;
		each2[vi][di]+=xi;
	}
	L=0;
	dfs(1,0);
	rb(i,1,n){
		printf("%I64d ",dp[i]);
	}
	return 0;
}