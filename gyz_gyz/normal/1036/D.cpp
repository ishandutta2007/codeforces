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
#define N 400000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,ans;ll a[N],b[N]; 
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&a[i]);
	scanf("%d",&m);
	rep(i,1,m)scanf("%I64d",&b[i]);
	for(;;){
		while(a[n]!=b[m])if(a[n]<b[m]){
			if(n==1){printf("-1");return 0;}
			a[n-1]+=a[n];n--;
		}else{
			if(m==1){printf("-1");return 0;}
			b[m-1]+=b[m];m--;
		}
		ans++;n--;m--;if((!n)||(!m))break;
	}
	if(n||m)printf("-1");else printf("%d",ans);
}