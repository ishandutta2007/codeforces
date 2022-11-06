#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,tot,x;bool u;char c[N];
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	rep(i,1,n)tot+=c[i]-'0';
	if(!tot){printf("YES");return 0;}
	rep(i,1,tot-1){x=0;u=1;
		rep(j,1,n){
			x+=c[j]-'0';
			if(x>i){u=0;break;}
			if(x==i)x=0;
		}
		if(x)u=0;
		if(u){printf("YES");return 0;}
	}printf("NO");
}