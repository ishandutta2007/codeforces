/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
vector<int> t;
int e[26][26];
int n,k;
void dfs(int now){
	rep(i,k) if(e[now][i]){
		e[now][i]--;
		dfs(i);
	}
	t.PB(now);
}
int main(){
	scanf("%d%d",&n,&k);
	int tot=k*k;
	tot=(n-1)/tot;
	rep(i,26)
	rep(j,26)
	e[i][j]=tot;
	dfs(0);
	int cnt=0;
	reverse(ALL(t));
	memset(e,0,sizeof(e));
	rep(i,26)
	rep(j,26)
	if(i!=t.back()||j)
	e[i][j]=1;
	vector<int> tmp=t;
	t.clear();
	dfs(0);
	reverse(ALL(t));
	for(auto it:t){
		tmp.PB(it);
	}
	t=tmp;
	for(auto it:t){
		++cnt;
		if(cnt>n) break;
		cout<<char('a'+it);
	}
	return 0;
}