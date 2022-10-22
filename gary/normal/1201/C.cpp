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
int n,k;
int a[200000+10];
bool cmp(int A,int B) {
	return A>B; 
}
bool check(LL x){
	LL need=0;
	rb(i,1,(n>>1)){
		if(a[i]<x){
			need+=x-a[i];
		}
	}
//	cout<<a[(n>>1)+1]<<endl;
	if(a[(n>>1)+1]>x) return false;
	need+=x-a[(n>>1)+1];
//	cout<<need<<" "<<x<<endl;
	return need<=k;
}
int main(){
	scanf("%d %d",&n,&k);
	rb(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	LL l=a[(n>>1)+1],r=2000000000+1;
	while(l<r-1){
		LL mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl; 
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
//	cout<<"d"<<endl;
//	cout<<check(2000000000)<<endl;
	printf("%I64d\n",l);
	return 0;
}