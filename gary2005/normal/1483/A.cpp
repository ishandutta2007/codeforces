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
int n,m;
vector<int> f[100000+233];
int cnt[100000+233];
int ans[100000+233];
int cnt2[100000+233];
void solve(){
	scanf("%d%d",&n,&m);
	rb(i,1,m) f[i].clear();
	rb(i,1,n) cnt[i]=cnt2[i]=0;
	rb(i,1,m){
		int k;
		scanf("%d",&k);
		rb(j,1,k){
			int ni;
			scanf("%d",&ni);
			f[i].PB(ni);
		}
	}
	rb(i,1,m){
		if(f[i].empty()){
			puts("NO");
			return ;
		}
		if(f[i].size()==1){
			cnt[f[i][0]]++;
			ans[i]=f[i][0];
			cnt2[f[i][0]]++;
		}
		else{
			for(auto it:f[i]) cnt2[it]++;
		}
	}
	rb(i,1,n){
		if(cnt[i]>(m+1)/2)
		{
			puts("NO");
			return ;
		}
	}
	int F=-1;
	rb(i,1,n){
		if(cnt2[i]>=(m+1)/2){
			F=i;
		}
	}
	int C=cnt[max(1,F)];
	rb(i,1,m){
		if(f[i].size()>1){
			if(F==-1){
				ans[i]=f[i][0];
			}
			else{
				bool ok=0;
				for(auto it:f[i]) ok|=(F==it);
				if(ok&&C<(m+1)/2){
					++C;
					ans[i]=F; 
				}
				else{
					ans[i]=(f[i][0]==F? f[i][1]:f[i][0]);
				}
			}
		}
	}
	puts("YES");
	rb(i,1,m){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}