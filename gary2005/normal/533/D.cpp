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
int n;
int x[100000+20],d[100000+20],l[100000+20],r[100000+20];
int sz;
LL value[100000+20];
int sta[100000+20];
int upper_bound(LL val){//idx,value[sta[idx]]>=val 
	if(!sz) return 0;
	int l=0,r=sz+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(value[sta[mid]]>=val) l=mid;
		else r=mid;
	}
	return l;
}
void add(int idx){
	while(sz&&value[sta[sz]]<=value[idx]) --sz;
	sta[++sz]=idx;
}
int main(){
	scanf("%d",&n);
	rb(i,0,n+1) scanf("%d",&x[i]);
	rb(i,1,n) scanf("%d",&d[i]);
	sta[++sz]=0;
	rb(i,1,n+1){
		while(sz>1&&2*d[sta[sz]]<x[i]-x[sta[sz-1]]){
			sz--;
		}
		l[i]=x[sta[sz]];
		sta[++sz]=i;
	}
	sz=0;
	sta[++sz]=n+1;
	rl(i,n,0){
		while(sz>1&&2*d[sta[sz]]<x[sta[sz-1]]-x[i]){
			sz--;
		}
		r[i]=x[sta[sz]];
		sta[++sz]=i;
	}
	sz=0;
	LL rest=x[n+1]-x[0];
	if(l[n+1]!=0){
		puts("0.00000");
		return 0; 
	} 
	rb(i,1,n){
		int idx=upper_bound(r[i]-2*d[i]);
		if(r[i]-2*d[i]<x[i]){
			if(idx) check_min(rest,1ll*x[i]-x[sta[idx]]);
	//		cout<<r[i]<<' '<<l[i]<<endl;
	//		cout<<"#"<<i<<' '<<rest<<endl;
	//		cout<<"$"<<i<<' '<<rest<<endl;
		}
		if(1ll*r[i]-2*d[i]<1ll*x[i]){
			check_min(rest,1ll*x[i]-x[0]);
		}
		if(1ll*l[i]+2*d[i]>1ll*x[i]){
			check_min(rest,1ll*x[n+1]-x[i]);
		}	
//		cout<<"@"<<i<<' '<<rest<<endl;
		value[i]=2ll*d[i]+l[i];
		if(value[i]>1ll*x[i])
			add(i);
	}
	printf("%.10f\n",rest/2.0);
	return 0;
}