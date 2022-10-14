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
const int MAXN=3e5+1;
int n,m;
int a[MAXN],b[MAXN],cnt[MAXN],pos[MAXN],c[MAXN];
int solve2(){
	rb(i,1,n){
		a[i]=c[i];
		pos[a[i]]=i;
	}
	int ANS=0;
	rb(i,1,n){
		if(a[i]!=b[i]){
			ANS++;
			int x,y;
			x=i;
			y=pos[b[i]];
			swap(pos[a[x]],pos[a[y]]);
			swap(a[x],a[y]);
		}
	}
	return ANS;
}
void solve(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) scanf("%d",&a[i]),c[i]=a[i];
	rb(i,0,n-1) cnt[i]=0;
	rb(i,1,n){
		cnt[(i+n-a[i])%n]++;
	}
	vector<int> ans;
	rb(i,0,n-1){
		if(cnt[i]*3>=n){
			rb(j,1,n){
				b[(j+i-1+n)%n+1]=j;
			}
			if(solve2()<=m){
				ans.PB(i);
			}
		}
	}
	printf("%d ",int(ans.size()));
	for(auto it:ans) printf("%d ",it);
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}