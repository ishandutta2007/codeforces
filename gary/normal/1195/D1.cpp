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
int a[100000+10];
int main(){
	int n;
	scanf("%d",&n);
	LL to=1;
	LL res=0;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,10){
		LL sum=0;
		rb(j,1,n){
			sum+=a[j]%10;
			a[j]/=10;
		}
		sum*=n;
//		cout<<sum<<to<<endl;
		sum%=998244353;
		res+=sum*to;
		res%=998244353;
//		to++;
		to*=10;
		res+=sum*to;
		res%=998244353;
		to*=10;
		to%=998244353;
	}
	printf("%I64d\n",res);
	return 0;
}