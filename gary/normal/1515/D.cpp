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
const int MAXN=2e5+233;
int n,l,r,c[MAXN];
int cnt[MAXN][2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&r);
		rb(i,1,n) cnt[i][0]=cnt[i][1]=0;
		rb(i,1,n){
			scanf("%d",&c[i]);
			cnt[c[i]][i<=l]++;
		}
		int rest=0;
		int L,R;
		L=R=0;
		rb(i,1,n){
			if((cnt[i][0]+cnt[i][1])&1){
				if(cnt[i][0]>cnt[i][1]){
					if(L){
						--L;
						cnt[i][1]++;
						continue;
					}
					rest++;
					R++;
					cnt[i][0]--;
				}
				else{
					if(R){
						--R;
						cnt[i][0]++;
						continue;
					}
					rest++;
					L++;
					cnt[i][1]--;
				}
			}
		}
		rb(i,1,n){
			while(L&&cnt[i][0]>cnt[i][1]){
				cnt[i][1]++;
				L--;
			}
			while(R&&cnt[i][1]>cnt[i][0]){
				cnt[i][0]++;
				R--;
			}
		}
		rb(i,1,n){
			assert((cnt[i][0]-cnt[i][1])%2==0);
			rest+=abs(cnt[i][0]-cnt[i][1])/2;
		}
		printf("%d\n",rest);
	}
	return 0;
}