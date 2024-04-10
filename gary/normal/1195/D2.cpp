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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string a[100000+10];
LL res=0;
map<int,LL> tot;
const int MOD=998244353;
LL ten_mi[30]={1};
void calc(int now,int wei){
	int num=a[now][wei]^48;
	wei=a[now].length()-wei;
	rb(i,1,10){
		LL tot_=tot[i];
		tot_%=MOD;
		if(i<wei){
			res+=((2*tot_)%MOD)*(LL)(num)*ten_mi[i+wei-1];
			res%=MOD;
		}
		else{
			res+=((tot_)%MOD)*(LL)(num)*ten_mi[wei*2-1];// 
			res%=MOD;
			res+=((tot_)%MOD)*(LL)(num)*ten_mi[wei*2-2];
			res%=MOD;
		}
//		cout<<i<<" "<<res<<endl;
	}
//	cout<<now<<" "<<wei<<"->>"<<res<<endl;
}
int main(){
	rb(i,1,29){
		ten_mi[i]=ten_mi[i-1]*10;
		ten_mi[i]%=MOD;
	}
	int n;//<=100000
	cin>>n;
	rb(i,1,n){
		cin>>a[i];
		tot[a[i].length()]++;
	}
	rb(i,1,n){
		int len=a[i].length();
		rb(j,0,len-1){
			calc(i,j);
		}
	}
	printf("%I64d\n",res);
	return 0;
}