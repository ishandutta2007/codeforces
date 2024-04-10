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
int a[200000+10];mp b[200000+10];
int res[200000+10];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,m) scanf("%d",&b[i].FIR),b[i].SEC=i;
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int l=1;
	rb(i,1,m){
		while(a[l]<=b[i].FIR&&l<=n){
			l++;
		}
		res[b[i].SEC]=l-1;
	}
	rb(i,1,m) printf("%d ",res[i]);
	return 0;
}