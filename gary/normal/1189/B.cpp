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
int l,r;
int res[100000+10];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	l=1;
	r=n;
	rb(i,1,n){
		if(i&1){
			res[l++]=a[i];
		}
		else{
			res[r--]=a[i];
		}
	}
	res[0]=res[n];
	res[n+1]=res[1];
	rb(i,1,n){
		if(res[i]>=res[i-1]+res[i+1]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	rb(i,1,n) printf("%d ",res[i]);
	return 0;
}