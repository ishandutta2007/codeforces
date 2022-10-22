/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
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
int c[4][100000+10];
LL res;
int degree[100000+10];
vector<int> each[100000+10];int n;
vector<int> order;
LL dfs(int now,int las,int laslas){
	if(now>n) return 0;
	int Is;
	rb(i,1,3){
		if(i!=las&&i!=laslas){
			Is=i;
		}
	}
	return (LL)(c[Is][order[now]])+dfs(now+1,Is,las);
}int col[100000+10];
void recover(int now,int las,int laslas){
	if(now>n) return;
	int Is;
	rb(i,1,3){
		if(i!=las&&i!=laslas){
			Is=i;
		}
	}
	col[order[now]]=Is;
//	printf("%d ",Is);
	recover(now+1,Is,las);
}
void dfs_put(int now,int las){
//	cout<<now<<endl;
	order.PB(now);
	if(degree[now]==1&&las!=-1) return;
	for(auto it:each[now]){
		if(it!=las){
			dfs_put(it,now);
		}
	}
}
int main(){
	
	cin>>n;
	rb(i,1,3)
		rb(j,1,n) scanf("%d",&c[i][j]);
	rb(i,1,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		each[u].PB(v);
		each[v].PB(u);
		degree[u]++;
		degree[v]++;
	}
	rb(i,1,n){
		if(degree[i]>=3){
			cout<<-1<<endl;
			return 0;
		}
	}
	int root;
	rb(i,1,n){
		if(degree[i]==1) {
			root=i;
			break;
		}
	}
	order.PB(1);
	dfs_put(root,-1);
//	cout<<root<<endl;
	res=(LL)1000000000*2000000;
	LL tmp=0;
	rb(i,1,3){
		rb(j,1,3){
			if(i==j) continue;
			tmp=c[i][order[1]]+c[j][order[2]];
			tmp+=dfs(3,j,i);
			res=min(res,tmp);
		}
	}
	cout<<res<<endl;
	rb(i,1,3){
		rb(j,1,3){
			if(i==j) continue;
			tmp=c[i][order[1]]+c[j][order[2]];
			tmp+=dfs(3,j,i);
			if(tmp==res){
				col[order[1]]=i;
				col[order[2]]=j;
				recover(3,j,i);
				break;
			}
		}
	}
	rb(i,1,n) cout<<col[i]<<" ";cout<<endl;
	return 0;
}