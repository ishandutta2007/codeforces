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
int tot1,tot2,totall;
mp a[300000+10];
bool cmp1(mp A,mp B){
	return A.FIR<B.FIR;
}
bool cmp2(mp A,mp B){
	return A.SEC<B.SEC;
}
bool cmp3(mp A,mp B){
	if(A.FIR!=B.FIR) return A.FIR<B.FIR;
	return A.SEC<B.SEC;
}
LL JIECHEN[300000+10]={1};
LL REMIND=0;int MOD= 998244353;
int main(){
	a[0]=II(INF,INF);
	int n;
	cin>>n;
	rb(i,1,n) JIECHEN[i]=JIECHEN[i-1]*i,JIECHEN[i]%=MOD;
	REMIND=JIECHEN[n];
//	cout<<REMIND<<endl;
	LL minus=1;
	rb(i,1,n){
		scanf("%d %d",&a[i].FIR,&a[i].SEC);
	}
	sort(a+1,a+1+n,cmp1);
	rb(i,1,n){
	if(a[i].FIR==a[i-1].FIR){
		tot1++;	
	}
	else{
		minus*=JIECHEN[tot1];
		minus%=MOD;
		tot1=1;
	}
	}
	minus*=JIECHEN[tot1];minus%=MOD;
	REMIND-=minus;
	if(REMIND<0) REMIND+=MOD;
//	cout<<REMIND<<endl;
	sort(a+1,a+1+n,cmp2);
	minus=1;
	rb(i,1,n){
	if(a[i].SEC==a[i-1].SEC) tot2++;
	else {
		minus*=JIECHEN[tot2];
		minus%=MOD;
		tot2=1;
	}
	} 
	minus*=JIECHEN[tot2];
	minus%=MOD;
	REMIND-=minus;
	if(REMIND<0) REMIND+=MOD;
	sort(a+1,a+1+n,cmp3);
	int OK=1;
	a[0]=II(0,0);
	rb(i,1,n){
		if(!(a[i].FIR>=a[i-1].FIR&&a[i].SEC>=a[i-1].SEC)){
//		cout<<a[i].FIR<<" "<<a[i].SEC<<" "<<a[i-1].FIR<<" "<<a[i-1].SEC<<endl;
		OK=false;}
	}
//	cout<<REMIND<<endl;	
	if(OK){
		minus=1;
		rb(i,1,n){
			if(a[i].FIR==a[i-1].FIR&&a[i].SEC==a[i-1].SEC){
				totall++;
			}
			else{
				minus*=JIECHEN[totall];
				minus%=MOD;
				totall=1;
			}
		}
		minus*=JIECHEN[totall];
		minus%=MOD;
//		cout<<minus<<" s"<<endl;
		REMIND+=minus;
		REMIND%=MOD;
	}
	cout<<REMIND<<endl;
	return 0;
}