/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
int cnt=0;
int son[40*(200000+20)][2];
int siz[40*(200000+20)];
void insert(int num,int now=0,int pos=0){
	siz[now]++;
	if(pos==30) {
		return;	
	}
	int digit=(num>>(29-pos))&1;
	if(!son[now][digit]){
		son[now][digit]=++cnt;
	} 
	insert(num,son[now][digit],pos+1);
} 
int a[200000+20];
int tmp[40*(200000+20)];
void pre(int now){
	tmp[now]=INF;
	if(son[now][0]){
		pre(son[now][0]);
		check_min(tmp[now],tmp[son[now][0]]+(son[now][1]? siz[son[now][1]]:0));
	}
	if(son[now][1]){
		pre(son[now][1]);
		check_min(tmp[now],tmp[son[now][1]]+(son[now][0]? siz[son[now][0]]:0));
	}
	if(tmp[now]==INF) tmp[now]=0;
}
int dfs(int now){
	if(son[now][0]&&son[now][1]){
		return min(dfs(son[now][0])+tmp[son[now][1]],dfs(son[now][1])+tmp[son[now][0]]);
	}
	if(son[now][0]||son[now][1]){
		if(son[now][0]){
			return dfs(son[now][0]);
		}
		else{
			return dfs(son[now][1]);
		}
	}
	else
		return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n)
		scanf("%d",&a[i]);
	rb(i,1,n){
		insert(a[i]);
	}
	pre(0);
	int rest=dfs(0);
	cout<<rest<<endl;
	return 0;
}
/** 
  * trie    
  *  
  *
  *
  **/