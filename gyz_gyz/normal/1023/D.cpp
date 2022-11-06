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
int n,m,a[N],st[N],ed[N],fr[N],nt[N];bool u;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,0,n)fr[i+1]=i,nt[i]=i+1;
	rep(i,1,n)if(a[i]){
		if(!st[a[i]])st[a[i]]=i;ed[a[i]]=i;
	}
	if(!st[m]){
		rep(i,1,n)if(!a[i]){
			nt[fr[i]]=nt[i];fr[nt[i]]=fr[i];
			u=1;a[i]=m;break;
		}
		if(!u){printf("NO");return 0;}
	}	
	dep(i,m,1)if(st[i])
		for(int j=st[i];j<=ed[i];j=nt[j]){
			if(!a[j])a[j]=i;
			if(a[j]!=i){printf("NO");return 0;}
			nt[fr[j]]=nt[j];fr[nt[j]]=fr[j];
		}
	printf("YES\n");
	rep(i,1,n)if(!a[i])printf("1 ");else printf("%d ",a[i]);
}