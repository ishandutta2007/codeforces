#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2000
#define ll long long
#define pb push_back
#define mo 1000000007
#define add(x,y) x=(x+(y))%mo;
using namespace std;
int n,x;
int main(){
	scanf("%d",&n);x=1;
	while(n>1){
		rep(i,2,n)if(n/i>n/(i+1)){
			rep(j,1,n-n/i)printf("%d ",x);
			x*=i;n/=i;break;
		}
	}
	printf("%d",x);
}