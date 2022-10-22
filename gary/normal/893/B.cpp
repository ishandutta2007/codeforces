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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int res=0;
bool check(int x){
	int k=1;
	while(((1<<k)-1)*(1<<(k-1))<=x){
		if(((1<<k)-1)*(1<<(k-1))==x) return 1;
		k++;
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0){
			if(check(i)) res=max(res,i);
			if(check(n/i)) res=max(res,n/i);
		}
	}
	printf("%d\n",res);
	return 0;
}