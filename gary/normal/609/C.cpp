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
int b[100000+10];
int n,sum,m[100000+10];
bool cmp(int A,int B){
	return A>B;
}
LL res=0;
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&m[i]);
		sum+=m[i];
	}
	rb(i,1,sum%n){
		b[i]=sum/n+1;
	}
	rb(i,sum%n+1,n){
		b[i]=sum/n;
	}
	sort(m+1,m+1+n,cmp);
	rb(i,1,n){
		res+=abs(m[i]-b[i]);
	}
	printf("%I64d\n",res>>1);
	return 0;
}