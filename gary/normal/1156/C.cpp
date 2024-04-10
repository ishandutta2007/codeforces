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
int n,z;
int x[200000+10];
bool check(int X){
	int l=1;
	rb(i,1,X){
		while(l<=n&&x[l]-x[i]<z){
			l++;
		}
		if(l>n) return false;
		l++;
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&z);
	rb(i,1,n) scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	int l=0,r=(n>>1)+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%d\n",l);
	return 0;
}