#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define eps 1e-18
using namespace std;
int n;ll x,y;bool u;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%I64d%I64d",&x,&y);
		if(x-y>1)printf("NO\n");else{x=x*2-1;u=0;
			rep(i,2,x){
				if(!(x%i)){u=1;printf("NO\n");break;}
				if(x/i<=i)break;
			}
			if(!u)printf("YES\n");
		}
	}
}