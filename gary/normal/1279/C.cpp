/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int deep[100000+10],n,m,p[100000+10];
void solve(){
	cin>>n>>m;
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		deep[ai]=i;
	}
	rb(i,1,m){
		scanf("%d",&p[i]);
	}
	LL res=0;
	int max_deep=-1;
	rb(i,1,m){
		if(deep[p[i]]>max_deep){
			max_deep=deep[p[i]];
			res+=(deep[p[i]]-i+1)*2-1;
		}
		else{
			res++;
		}
	}
	cout<<res<<endl;
} 
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}