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
int n,m;
vector<int> each[200000+10];
map<int,int> MM;
int res;
map<int,int> v;
void dfs(int now,int flag){
	if(v[now]) return;
	MM[now]=flag;
	res+=flag;
	v[now]=1;
	int sz=each[now].size();
	rb(i,0,sz-1){
		if(!v[each[now][i]])
		dfs(each[now][i],flag^1);
	}
}
int main(){
//	double st=time(0);
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
//		memset(v,0,sizeof(v));	
		v.clear();
		scanf("%d %d",&n,&m);
		rb(i,1,n) each[i].clear();
		MM.clear();
		res=0;
		rb(i,1,m){
			int ui,vi;
			scanf("%d %d",&ui,&vi);
			each[ui].PB(vi);
			each[vi].PB(ui);
		}
		dfs(1,1);
		int flag=(res<=n/2);
		printf("%d\n",flag? res : n-res);
		rb(i,1,n){
			if(MM[i]){
				if(flag) printf("%d ",i);
			}
			else{
				if(!flag) printf("%d ",i);
			}
		}
		printf("\n");
	}
//	cout<<time(0)-st;
	return 0;
}