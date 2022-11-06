#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x,ls,tot,a[N];bool pt;
int main(){
	scanf("%d",&n);tot=n-1;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]<0){
			pt^=1;if((!x)||(a[x]<a[i]))x=i;
		}
	}
	if(pt)ls=x,a[x]=0;
	rep(i,1,n)if((a[i]==0)&&(i!=x)){
		if(ls){
			printf("1 %d %d\n",ls,i);tot--;
		}ls=i;
	}
	if(ls&&tot)printf("2 %d\n",ls);ls=0;
	rep(i,1,n)if(a[i]!=0){
		if(ls)printf("1 %d %d\n",ls,i);ls=i;
	}
}