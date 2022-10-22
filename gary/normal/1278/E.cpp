/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int all[500000+10],l[500000+10],used[1000000+10],r[500000+10],n,children[500000+10],ok;
vector<int> each[500000+10]; 
void dfs(int now,int prev){
	if(prev==-1){
		children[now]=each[now].size();
	}
	else{
		children[now]=each[now].size()-1;
	}
	for(auto it:each[now]){
		if(it!=prev){
			dfs(it,now);
			all[now]+=all[it];
		}
	}
	all[now]+=children[now];
}
void build(int now,int prev){
	int tmp=ok;
	l[now]=ok+all[now]*2-children[now]+1;
	for(auto it:each[now]){
		if(it!=prev){
			build(it,now);
			ok--;	
		}
	}
	ok=tmp+(all[now]+1)*2;
}
vector<int> r_bound;
int pt=0;
void calc(int now,int prev){
	for(auto it:each[now]){
		if(it!=prev){
			calc(it,now);
		}
	}
	int SZ=each[now].size();
	if(SZ)
		rl(i,SZ-1,0)
			if(each[now][i]!=prev)
			r[each[now][i]]=r_bound[pt++];
}
int main(){
	cin>>n;
	rb(i,1,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		each[u].PB(v);
		each[v].PB(u);
	}
	dfs(1,-1);
	build(1,-1);
	rb(i,1,n) used[l[i]]=1; 
	rb(i,1,2*n) {
		if(!used[i]) {
			r_bound.PB(i);
//			cout<<i<<endl;
		}
	}
	sort(ALL(r_bound));
	calc(1,-1);
	r[1]=r_bound[pt++];
	rb(i,1,n){
		printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}