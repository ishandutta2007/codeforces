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
int a[200000+20];
void solve(){
	int n;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int bs=INF;
	rb(i,1,n-1) check_min(bs,a[i+1]-a[i]);
	if(a[n]-a[1]==bs){
		rb(i,1,n){
			printf("%d ",a[i]);
		}
	}
	else{
		if(a[2]-a[1]==bs){
			rb(i,1,n){
				if(i!=2){
					printf("%d ",a[i]);
				}
			}
			printf("%d ",a[2]);
		}
		else{
			if(a[n]-a[n-1]==bs){
				printf("%d ",a[n-1]);
				rb(i,1,n){
					if(i!=n-1){
						printf("%d ",a[i]);
					}
				}
			}
			else{
				rb(i,1,n-1){
					if(a[i+1]-a[i]==bs){
						printf("%d ",a[i]);
						rb(j,i+2,n){
							printf("%d ",a[j]);
						}
						rb(j,1,i-1){
							printf("%d ",a[j]);
						}
						printf("%d ",a[i+1]);
						break ;
					}
				}
			}
		}
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}