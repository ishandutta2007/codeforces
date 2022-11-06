#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
ll l1,r1,t1,l2,r2,t2,p,nx;
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&t1,&l2,&r2,&t2);
	if(l1>l2){
		swap(l1,l2);swap(r1,r2);
	}
	p=__gcd(t1,t2);nx=(l2-l1)/p*p;
	l1+=nx;r1+=nx;
	printf("%I64d\n",max(0ll,max(min(r1,r2)-max(l1,l2)+1,min(r1+p,r2)-max(l1+p,l2)+1)));
}