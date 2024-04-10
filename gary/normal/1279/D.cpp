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
int k[1000000+10],n;
LL res=0; 
const int MOD= 998244353;
vector<int> each[1000000+10]; 
LL my_pow(LL A,int times){
	if(times==0) return 1;
	LL tmp;
	if(times%2==0){
		tmp=my_pow(A,times/2);
		tmp*=tmp;
		tmp%=MOD;
	}
	else{
		tmp=my_pow(A,times/2);
		tmp*=tmp;
		tmp%=MOD;
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
LL div_(LL A,LL B){
	return A*my_pow(B,MOD-2)%MOD;
}
int main(){
	
	cin>>n;
	rb(i,1,n){
		scanf("%d",&k[i]);
		rb(j,1,k[i]){
			int ai;
			scanf("%d",&ai);
			each[ai].PB(i);
		}
	}
	rb(i,1,1000000){
		LL tmp=0;
		if(each[i].size()){
			for(auto it:each[i]){
				LL t1,t2;
				t1=1ll;
				t2=n;
				t2*=k[it];
				t2%=MOD;
//				cout<<i<<" "<<it<<" "<<" "<<t1<<" "<<t2<<endl;
				tmp+=div_(t1,t2);
				tmp%=MOD;
			}
			tmp*=each[i].size();
			tmp%=MOD;
			tmp=div_(tmp,n);
			tmp%=MOD;
			res+=tmp;
			res%=MOD;
		}
		
	}
	cout<<res<<endl;
	return 0;
}