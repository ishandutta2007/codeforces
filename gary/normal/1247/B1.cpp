/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
set<int> ty;
int a[200000+10],cnt[1000000+10];
void solve(){
	ty.clear();
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);
	rb(i,1,n) scanf("%d",&a[i]),cnt[a[i]]=0;
	int res=INF;
	rb(i,1,d){
		cnt[a[i]]++;
		if(cnt[a[i]]==1){
			ty.insert(a[i]);
		}
	}
	res=ty.size();
	rb(i,d+1,n){
		cnt[a[i-d]]--;
		if(!cnt[a[i-d]]){
			ty.erase(a[i-d]);
		}
		cnt[a[i]]++;
		ty.insert(a[i]);
		res=min(res,(int)ty.size());
	} 
	printf("%d\n",res);	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}