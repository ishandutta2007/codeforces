#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 300010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,a[N],b[N];
void tr(int x){
	rep(i,2,n)if(!((!(a[i]%x))||(!(b[i]%x))))return;
	printf("%d",x);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,2,a[1]){
		if(i*i>a[1])break;
		if(!(a[1]%i)){
			tr(i);while(!(a[1]%i))a[1]/=i;
		}
	}
	if(a[1]>1)tr(a[1]);
	rep(i,2,b[1]){
		if(i*i>b[1])break;
		if(!(b[1]%i)){
			tr(i);while(!(b[1]%i))b[1]/=i;
		}
	}
	if(b[1]>1)tr(b[1]);printf("-1");
}