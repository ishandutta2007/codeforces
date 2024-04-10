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
int n;
pair<LL,LL> a[100000+20];
bool cmp(pair<LL,LL> A,pair<LL,LL> B){
	return A.SEC<B.SEC;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%lld%lld",&a[i].FIR,&a[i].SEC);
	sort(a+1,a+1+n,cmp);
	LL ans=0;
	int r=n;
	LL tot=0;
	rb(i,1,n){
		if(a[i].FIR==0) continue;
		while(r>=1&&a[r].FIR==0) --r;
		if(tot>=a[i].SEC){
			ans+=a[i].FIR;
			tot+=a[i].FIR;
			a[i].FIR=0;
			continue;
		}
		else{
			while(r>=1){
				if(tot+a[r].FIR>=a[i].SEC){
					LL Tmp=a[i].SEC-tot;
					tot+=Tmp;
					a[r].FIR-=Tmp;
					ans+=Tmp+Tmp;
					break;
				}
				else{
					tot+=a[r].FIR;
					ans+=a[r].FIR+a[r].FIR;
					a[r].FIR=0;
				}
				--r;
			}
			if(tot==a[i].SEC){
				ans+=a[i].FIR;
				tot+=a[i].FIR;
				a[i].FIR=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}