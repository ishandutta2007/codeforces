/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[1000000+10],rev[1000000+10];
int tmp,v[1000000+10],res[1000000+10];
void dfs(int now){
	if(v[now]) return;
	v[now]=1;
	tmp++;
	for(auto it:each[now]){
		dfs(it);
	}
}
void dfs2(int now){
	if(v[now]) return;
	v[now]=1;
	tmp++;
	for(auto it:rev[now]){
		dfs2(it);
	}
}
void recover(int now){
	if(res[now]) return;
	res[now]=1;
	tmp++;
	for(auto it:each[now]){
		recover(it);
	}
}
void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n) each[i].clear(),rev[i].clear(),v[i]=res[i]=0;
	rb(i,1,m){
		int A,B;
		scanf("%d %d",&A,&B);
		if(A!=B){
			each[A].PB(B);
			rev[B].PB(A);
		} 
	}tmp=0;dfs(1);
	if(tmp!=n){tmp=0;
		recover(1);
		puts("Yes");
		printf("%d %d\n",tmp,n-tmp);
		rb(i,1,n) if(res[i]) printf("%d ",i);puts("");
		rb(i,1,n) if(!res[i]) printf("%d ",i);puts("");
	}
	else{tmp=0;
		rb(i,1,n) v[i]=0;
		dfs2(1);
		if(tmp==n){
			puts("No");
			return;
		}
		puts("Yes");
		rb(i,1,n) if(!v[i]){
			tmp=0;
			recover(i);
			printf("%d %d\n",tmp,n-tmp);
			rb(i,1,n) if(res[i]) printf("%d ",i);puts("");
			rb(i,1,n) if(!res[i]) printf("%d ",i);puts("");
			return;
		}
	}
}
int main(){	
	int t;
	cin>>t;
	while(t--) solve(); 
	return 0;
}