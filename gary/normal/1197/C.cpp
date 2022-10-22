//* AuThOr GaRyMr *//
//SOLUTION by Gwj
//cost=a[i]-a[1]+a[j]-a[i+1]+a[k]-a[j+1]+......+a[n]-a[l+1]
//    =a[n]-a[1]+a[i]-a[i+1]+a[j]-a[j+1]+a[k]-a[k+1]
//	  such 1<=i,j,k<n,and k-1 pairs of these
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
LL a[300000+10];
vector<LL> pp;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	rb(i,1,n){
		scanf("%I64d",&a[i]);
		if(i!=1) pp.PB(a[i-1]-a[i]);
	}
	LL cost=a[n]-a[1];
	sort(pp.begin(),pp.end());
	rb(i,1,k-1){
		cost+=pp[i-1];
	}
	printf("%I64d\n",cost);
	return 0;
}