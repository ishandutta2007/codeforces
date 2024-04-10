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
typedef bitset<2501> Bitset;
int n,a[2505][2505]; 
Bitset col[2505];
pair<int,mp> val[2505*2505];
int main(){
	scanf("%d",&n);
	rb(i,1,n) rb(j,1,n){
		scanf("%d",&a[i][j]);	
		val[(i-1)*n+j]=II(a[i][j],II(i,j));
	} 
	rb(i,1,n) if(a[i][i]){
		puts("NOT MAGIC");
		return 0;
	}
	rb(i,1,n) rb(j,1,n) if(a[i][j]!=a[j][i]){
		puts("NOT MAGIC");
		return 0;
	}
	sort(val+1,val+1+n*n);
	reverse(val+1,val+1+n*n);
	for(int i=1;i<=n*n;){
		int j=i;
		for(j;j<=n*n&&val[j].FIR==val[i].FIR;++j);
		rb(k,i,j-1) col[val[k].SEC.SEC].set(val[k].SEC.FIR);
		rb(k,i,j-1) if((col[val[k].SEC.SEC]|col[val[k].SEC.FIR]).count()!=n){
			puts("NOT MAGIC");
			return 0;
		}
		i=j;
	}
	puts("MAGIC");
	return 0;
}