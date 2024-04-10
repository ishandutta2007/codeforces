#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
const int MOD=998244353 ;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL fac[200001]={1};
LL du[200001];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rb(i,1,n){
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
	}
	rb(i,2,n){
		int ai,bi;
		cin>>ai>>bi;
		du[ai]++;du[bi]++;
	}
	LL res=n;
	rb(i,1,n){
		res*=fac[du[i]];
		res%=MOD;
	}
	cout<<res<<endl;
	return 0;
}