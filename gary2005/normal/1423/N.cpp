/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
const int MAXN=12500+20;
map<mp,int> weight;
int n,k,have[MAXN],tot[MAXN];
vector<int> g[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,k){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b) swap(a,b);
		g[a].PB(b);
		tot[a]++,tot[b]++;
		weight[II(b,a)]=1;
	} 
	rb(i,1,n){
		map<int,int> oc;
		vector<int> minu,addi;
		for(auto it:g[i]){
			oc[tot[it]]=1;
			if(have[it]){addi.PB(it);}
			else {minu.PB(it);}
		}
		int l,r,now=tot[i];
		while(oc[now]){
			now++;
		}
		r=now;
		now=tot[i];
		while(oc[now]){
			now--;
		}
		l=now;
		if((r-tot[i])<=addi.size()){
			rb(j,1,r-tot[i]){
				int pre=addi[j-1];
				weight[II(pre,i)]++;
				have[pre]--;
			}
			tot[i]=r;
		}
		else{
			assert((tot[i]-l)<=minu.size());
			rb(j,1,tot[i]-l){
				int pre=minu[j-1];
				weight[II(pre,i)]--;
				have[pre]++;
			}
			tot[i]=l;
		}
	}
	vector<int> v;
	rb(i,1,n) if(have[i]) v.PB(i);
	cout<<v.size()<<endl;
	for(auto it:v)
		printf("%d ",it);
	puts("");
	for(auto ite=weight.begin();ite!=weight.end();ite++){
		printf("%d %d %d\n",(ite->FIR).FIR,(ite->FIR).SEC,ite->SEC);
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/