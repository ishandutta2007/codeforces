/*
AuThOr Gwj
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MOD=1e9+7;
int n;
int cnt[1000000+20];
LL pre[1000000+20];
bool flag[1000000+20];
/*

i*c(n,i) 
=
n*(n-1,i)(0<=i<=n-1)
=
n*2^(n-1) 
*/
LL calc(int x){
	if(x==0) return 0;
	return (LL)x*pre[x-1]%MOD;
}
int cnt2[1000000+20];
int flag2[1000000+20];
LL num[1000000+20];
int main(){
	fastio;
	R(n);
	pre[0]=1;
	rb(i,1,1000000)
		pre[i]=pre[i-1]*2,pre[i]%=MOD;
	for(int i=2;i<=1000000;i++){
		if(!flag[i]){
			for(int j=i;j<=1000000;j+=i){
				int tmp=j;
				while(tmp%i==0){ 
					cnt[j]++;
					tmp/=i;
				}
				flag[j]=1;
			}
		}
	}
	rb(i,1,n){
		int ai;
		R(ai);
		flag2[ai]++;
	}
	for(int i=2;i<=1000000;i++){
		for(int j=i;j<=1000000;j+=i){
			cnt2[i]+=flag2[j];
		}
	}
	LL res=0;
	
	rl(i,1000000,2){
		num[i]=calc(cnt2[i]);
		for(int j=i+i;j<=1000000;j+=i){
			num[i]-=num[j];
			num[i]+=MOD;
			num[i]%=MOD; 
		}
	}
	rb(i,2,1000000){
		res+=num[i]*i%MOD;
		res%=MOD;
	}
	cout<<res<<endl;
	return 0;
}