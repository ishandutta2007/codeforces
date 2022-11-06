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
int n,t,x,y,ls,f[N],a[N];bool v[N];
int main(){
	scanf("%d",&n);t=1;
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);f[i]=n;
		if((x!=n)&&(y!=n)){printf("NO");return 0;}
		if(x!=n)a[x]++;else a[y]++;
	}
	rep(i,1,n-1)if(a[i]){ls=n;
		rep(j,1,a[i]-1){
			while(v[t])t++;
			if(t>=i){printf("NO");return 0;}
			v[t]=1;f[t]=ls;ls=t;
		}
		v[i]=1;f[i]=ls;
	}
	printf("YES\n");
	rep(i,1,n-1)printf("%d %d\n",i,f[i]);
}