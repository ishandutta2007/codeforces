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
int a[200000+1];
bool used[200000+1];
bool have[200000+1];
bool cmp(int A,int B){
	return have[A]<have[B];
}
int b[200000+1];
void solve(){
	scanf("%d",&n);
	rb(i,1,n) have[i]=0;
	rb(i,1,n) scanf("%d",&a[i]),have[a[i]]=1;
	rb(i,1,n) used[i]=0;
	int cnt=0;
	vector<int> v;
	rb(i,1,n) v.PB(i);
	sort(ALL(v),cmp);
	vector<int> bad[2];
	for(auto i:v){
		if(used[a[i]]){
			if(have[i]) bad[0].PB(i);
			else bad[1].PB(i);
		}
		else b[i]=a[i],cnt++;
		used[a[i]]=1;
	}
	if(bad[1].size()){
		assert(bad[0].size());
		int Tmp=bad[0].back();
		bad[0].POB();
		for(auto it:bad[1]){
			b[Tmp]=it;
			used[it]=1;
			Tmp=it;
		}
		bad[0].PB(Tmp);
	}
	vector<int> Emp;
	rb(i,1,n) if(!used[i]) Emp.PB(i);
	for(auto it:bad[0]){
		b[it]=Emp.back();
		Emp.POB();
	}
	printf("%d\n",cnt);
	rb(i,1,n){
		printf("%d ",b[i]);
	}puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}