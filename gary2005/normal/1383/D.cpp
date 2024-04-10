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
const int MAXN=252;
int row[MAXN*MAXN],col[MAXN*MAXN],n,m;
int a[MAXN][MAXN];
int rest[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) rb(j,1,m) scanf("%d",&a[i][j]);
	rb(i,1,n){
		mp best={-INF,-INF};
		rb(j,1,m){
			check_max(best,II(a[i][j],j));
		}
		row[best.FIR]=true;
	}
	rb(j,1,m){
		mp best={-INF,-INF};
		rb(i,1,n){
			check_max(best,II(a[i][j],i));
		}
		col[best.FIR]=true;
	}
	vector<int> unused;
	vector<mp> pos;
	int x=0,y=0;
	rl(i,n*m,1){
		if(!col[i]&&!row[i]){
			unused.PB(i);
			continue;
		}
		if(col[i]){
			++y;
			rl(j,x-1+row[i],1){
				pos.PB({j,y});
			}
		}
		if(row[i]){
			++x;
			rl(j,y-1,1){
				pos.PB({x,j});
			}
		}
//		cout<<x<<" "<<y<<endl;
		rest[x][y]=i;
	}
	for(auto it:pos){
		
	}
	rep(i,pos.size()){
		rest[pos[i].FIR][pos[i].SEC]=unused[i];
	}
	rb(i,1,n){
		rb(j,1,m){
			cout<<rest[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}