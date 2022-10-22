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
int n,r;
mp a[101];
bool cmp(mp A,mp B){
	return A.FIR<B.FIR; 
} 
bool cmp2(mp A,mp B){
	return B.FIR+B.SEC<A.FIR+A.SEC;
}
int v[101];
mp b[101];
int main(){
	cin>>n>>r;
	rb(i,1,n) cin>>a[i].FIR>>a[i].SEC;
	sort(a+1,a+1+n,cmp);
	rb(i,1,n){
		if(a[i].SEC>=0){
			if(r<a[i].FIR){
				puts("NO");
				return 0;
			}
			r+=a[i].SEC;
		}
	}
	int tmpn=0;
	rb(i,1,n)
	{
		if(a[i].SEC<0){
			b[++tmpn]=a[i];
		}
	 } 
	n=tmpn;
	rb(i,1,n) a[i]=b[i];
	sort(a+1,a+1+n,cmp2);
	rb(i,1,n){
//		cout<<a[i].FIR<<" "<<a[i].SEC<<endl; 
		if(a[i].SEC<0){
			if(r<a[i].FIR){
				puts("NO");
				return 0;
			}
			r+=a[i].SEC;
		}
	}
	if(r<0) puts("NO"); 
	else puts("YES");
	return 0;
}////