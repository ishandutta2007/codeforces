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
const int MAXN=3e5+233;
vector<int> v[MAXN];
SRAND;
int n,q,a[MAXN];
int query(int x,int l,int r){
	return upper_bound(ALL(v[x]),r)-lower_bound(ALL(v[x]),l);
}
int get(int l,int r){
	rb(i,1,30){
		int x=random((r-l+1));
		x=a[l+x];
		if(query(x,l,r)>(r-l+2)/2) return x;
	}
	return -1;
}
int main(){
	scanf("%d%d",&n,&q);
	rb(i,1,n) scanf("%d",&a[i]),v[a[i]].PB(i);
	rb(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		int x=get(l,r);
		if(x==-1) puts("1");
		else{
			int A=query(x,l,r);
			if(2*(r-l+1-A)<A){
				printf("%d\n",r-l+1-2*(r-l+1-A));
				continue;
			}
			A-=r-l+1-A;
			printf("%d\n",A);
		}
	}
	return 0;
}