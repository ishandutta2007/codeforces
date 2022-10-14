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
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		scanf("%d%d",&n,&x);
		vector<int> a(n);
		int sum=0;
		rep(i,n){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==x) puts("NO");
		else{
			puts("YES");
			sort(ALL(a));
			sum=0;
			rep(i,a.size()){
				if(sum+a[i]==x){
					printf("%d %d ",a[i+1],a[i]);
					sum+=a[i+1]+a[i];
					i++;
				}
				else{
					printf("%d ",a[i]);
					sum+=a[i];
				}
			}
			puts("");
		}
	}
	return 0;
}