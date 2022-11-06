#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 1000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,a[N],v[N];bool pt,t[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);v[a[i]]++;
	}
	rep(i,1,n)if(v[a[i]]==1){
		if(pt)t[i]=1,pt=0;else pt=1;
	}
	if(pt)rep(i,1,n)if(v[a[i]]>2){
		pt=0;t[i]=1;break;
	}
	if(pt){printf("NO");return 0;}
	printf("YES\n");
	rep(i,1,n)printf("%c",'A'+t[i]);
}