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
int n;
int a[100000+10];
mp dp[100000+10][18];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		dp[i][0]=II(a[i],0);
	}
	rb(i,1,17){
		rb(j,1,n){
			if((j+(1<<i)-1)>n)  continue;
			dp[j][i].SEC=dp[j][i-1].SEC+dp[j+(1<<(i-1))][i-1].SEC;
			dp[j][i].FIR=(dp[j][i-1].FIR+dp[j+(1<<(i-1))][i-1].FIR)%10;
			dp[j][i].SEC+=(dp[j][i-1].FIR+dp[j+(1<<(i-1))][i-1].FIR>=10);
//			cout<<" < "<<j<<","<<i<<":"<<dp[j][i].FIR<<","<<dp[j][i].SEC<<" > ";
		}
//		cout<<endl;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int tot=r-l+1;
		tot=int(log2(double(tot)));
//		cout<<tot<<endl;
		printf("%d\n",dp[l][tot].SEC);
	}
	return 0;
}