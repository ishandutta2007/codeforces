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
int n,m;
vector<int> each[300000+10];
vector<int> path;
map<int,int> used;
mp p[500000+10];
void solve()
{
	path.clear();
	scanf("%d %d",&n,&m);
	n=n+n+n;
	rb(i,1,n){
		each[i].clear();
		used[i]=false;
	}
	rb(i,1,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		p[i]=II(vi,ui);
		each[ui].PB(vi);
		each[vi].PB(ui);
	}
	rb(i,1,m){
		int vi,ui;
		vi=p[i].FIR;
		ui=p[i].SEC;
		if(!used[ui]&&!used[vi]){
			used[ui]=used[vi]=1;
			path.PB(i);
		}
	}
	if(path.size()>=n/3){
		puts("Matching");
//		int SZ=path.size();
		rep(i,n/3){
			printf("%d ",path[i]);
		}
		printf("\n");
	}
	else{
		puts("IndSet");
		int tot=0;
		rb(i,1,n){
			if(!used[i]){
				++ tot;
				printf("%d ",i);
				if(tot==n/3) break;
			}
		}
		printf("\n");
	}
}
int main(){
//	FREO;
	int T;
	scanf("%d",&T);
	while(T--){
		solve(); 
	}
	return 0;
}