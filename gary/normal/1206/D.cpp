//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
LL a[100000+10];
int have_each[100+10]; 
map<LL,int> v;
int res_1=INF;
void dfs(int now,int start,int step){
	if(step>=res_1) return;
	v[now]=true; 
	rb(i,1,n)
	{
		if(a[i]&a[now]){
			if(!v[i]){
				dfs(i,start,step+1);
			}
			else{
				if(i==start){
					if(step>=3){
						res_1=min(res_1,step);
						 break;
					}
				}
			}
		}
	}
	v[now]=false;
}
void solve1(){
	if(!n){
		puts("-1"); return;
	} 
	rb(i,1,n) dfs(i,i,1);
	cout<<(res_1==INF? -1:res_1);
}
int main(){
	// An amazing algorithm - GaryMr
	cin>>n;
	rb(i,1,n) {
		scanf("%I64d",&a[i]);
		if(!a[i]){
			i--;
			n--;
		}
	}
	if(n<150){
		solve1();
	}
	else{
		puts("3");
	}
	return 0;
}