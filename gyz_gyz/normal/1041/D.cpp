#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
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
#define pb push_back
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,h,tot,ans,t,l[N],r[N];
int main(){
	scanf("%d%d",&n,&h);t=1;
	rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	rep(i,1,n){
		tot+=r[i]-l[i];
		for(;r[i]-l[t]>=h+tot;t++)tot-=r[t]-l[t];
		if(tot>ans)ans=tot;
	}
	printf("%d",ans+h);
}