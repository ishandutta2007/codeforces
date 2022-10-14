/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
const int MAXN=300000+20;
vector<int> each[MAXN];
int n,k;
int p[MAXN];
int nex[MAXN];
bool root[MAXN];
int belong[MAXN];
void erro(){
	printf("0");
	exit(0);
}
vector<int> g[MAXN];
int ind[MAXN];
vector<int> order;
int ran[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n) scanf("%d",&p[i]);
	rb(i,1,k){
		int x,y;
		scanf("%d%d",&x,&y);
		root[y]=true;
		nex[x]=y;
	}
	int cnt=0;
	rb(i,1,n){
		if(!root[i]){
			++cnt;
			int now=i;
			while(true){
				belong[now]=cnt;
				each[cnt].PB(now);
				ran[now]=each[cnt].size();
				if(nex[now]==0) break;
				now=nex[now];
			}
		}
	}
	rb(i,1,n){
		if(belong[i]==belong[p[i]]){
			if(ran[p[i]]>ran[i]){
				erro();
			}
			continue;
		}
		g[belong[p[i]]].PB(belong[i]);
		ind[belong[i]]++;
	}
	queue<int> q;
	rb(i,0,cnt){
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto it:g[now]){
			if(!(--ind[it])){
				q.push(it);
			}
		}
		order.PB(now);
//		cout<<"!"<<now<<' '<<cnt<<endl;
	}
	if(order.size()!=cnt+1) erro();
	rb(i,1,order.size()-1){
		for(auto it:each[order[i]]){
			printf("%d ",it);
		}
	}
	return 0;
}