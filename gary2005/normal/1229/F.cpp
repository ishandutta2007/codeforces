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
const int MAXN=35000+233;
LL a[MAXN],l[MAXN],r[MAXN],n;
LL solve(LL x){// C(A[n]-> A[1])=x
	priority_queue<LL> L;
	priority_queue<LL,vector<LL>,greater<LL> > R;
	LL tagl=0,tagr=0;
	a[n]-=x;
	a[1]+=x;
	LL smallest=0,l1,r1,l2,r2;
	rb(i,1,n) L.push(0),R.push(0);
	l1=r1=l2=r2=0;
	rb(i,1,n){
		LL L_,R_;
		L_=r[i]-a[i];
		R_=a[i]-l[i];
		tagl-=L_;
		tagr+=R_;
		l1-=L_;
		r1-=L_;
		l2+=R_;
		r2+=R_;
//		cout<<"S:"<<l1<<' '<<r1<<" "<<l2<<" "<<r2<<' '<<smallest<<endl;
		assert(l2>=r1);
		if(0<=l2&&0>=r1){
			L.push(-tagl);
			R.push(-tagr);
		}
		else
		if(0<=r1&&0>=l1){
//			cout<<"!"<<endl;
			L.push(-tagl);
			L.push(-tagl);
			R.push(L.top()+tagl-tagr);
			smallest+=abs(L.top()+tagl);
			L.pop();
		}
		else
		if(0<=r2&&0>=l2){
//			cout<<"!"<<endl;
			R.push(-tagr);
			R.push(-tagr);
			L.push(R.top()+tagr-tagl);
			smallest+=abs(R.top()+tagr);
			R.pop();
		}
		else
		if(0<l1){
			smallest+=abs(L.top()+tagl);
			R.push(L.top()+tagl-tagr);
			L.pop();
		}
		else
		if(0>r2){
			smallest+=abs(R.top()+tagr);
			L.push(R.top()+tagr-tagl);
			R.pop();
		}
		else assert(0);
		if(L.empty()) l1=1e10,r1=-1e10;
		else{
			r1=L.top()+tagl;
			if(L.size()==1) l1=r1;
		}
		if(R.empty()) l2=1e10,r2=-1e10;
		else{
			l2=R.top()+tagr;
			if(R.size()==1) r2=l2;
		}
//		cout<<l1<<' '<<r1<<" "<<l2<<" "<<r2<<' '<<smallest<<endl;
	}
	smallest+=abs(x);
	a[n]+=x;
	a[1]-=x;
	if(!R.empty()&&R.top()+tagr<=0){
		int cnt=0;
		LL pre=R.top()+tagr;
		R.pop();
		while(true){
			++cnt;
			if(R.top()+tagr>=0){
				return smallest+1ll*cnt*(0-pre);
			}
			smallest+=1ll*cnt*(R.top()+tagr-pre);
			pre=R.top()+tagr;
			R.pop();
		}
		assert(0);
	}
	if(!L.empty()&&L.top()+tagl>=0){
		int cnt=0;
		LL pre=L.top()+tagl;
		L.pop();
		while(true){
			++cnt;
			if(L.top()+tagl<=0){
				return smallest+1ll*cnt*(pre);
			}
			smallest+=1ll*cnt*(pre-(L.top()+tagl));
			pre=L.top()+tagl;
			L.pop();
		}
		assert(0);
	}
	return smallest;
}
int main(){
	scanf("%lld",&n);
	rb(i,1,n) scanf("%lld%lld%lld",&a[i],&l[i],&r[i]);
//	cout<<solve(-1)<<endl;
//	return 0;
	LL lb,rb;
	lb=-1e10;
	rb=1e10;
	while(lb<rb){
		LL mid=(lb+rb)>>1;
		if(solve(mid+1)<solve(mid)) lb=mid+1;
		else rb=mid;
	}
	printf("%lld\n",solve(lb));
	return 0;
}