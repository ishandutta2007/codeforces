//* AuThOr GaRyMr *//
/*
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
//int dp[]
void solve(){
	vector<int> duan;
	int a,b;
	string s;
	cin>>a>>b>>s;
	int tot=0;
	rep(i,s.length()){
//		dp[i+1]=0;
		if(s[i]=='X'){
			duan.PB(tot);
			tot=0;
		}
		else {
			tot++;
		}
	}
//	cout<<duan[0]<<endl;
	duan.PB(tot);
	int ty1,ty2,ty3;
	ty1=ty2=ty3=0;
	for(auto it:duan){
		if(b<=it&&it<a) ty1++;
		if(a<=it&&it<b+b) ty2++;
		if(it>=b+b) ty3++; 
	}
	if(ty1){
		puts("NO");
		return;
	}
	if(ty3){
		if(ty3>=2){
			puts("NO");
			return;
		}
		else{
			int is=0;
			for(auto it:duan){
				if(it>=b+b){
					is=it;
				}
			}
			rb(i,1,is-a+1){
				int l1,l2;
				l1=i-1;
				l2=is-(i+a-1);
				if(!(b<=l1&&l1<a)&&!(b<=l2&&l2<a)&&!(l1>=b+b)&&!(l2>=b+b)){
					int tmpty2=ty2+1;
					if(l1>=a) tmpty2++;
					if(l2>=a) tmpty2++;
					if(tmpty2&1){
//						cout<<l1<<" "<<l2<<" "<<is<<" "<<tmpty2<<endl;
						puts("YES");
						return;
					}
				}
			}
			puts("NO");
		}
//		cout<<ty2<<endl;
	}
	else{
		if(ty2&1){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}
int main(){
	int q;
	cin>>q;
	while(q--){
		solve();
	}
	return 0;
}