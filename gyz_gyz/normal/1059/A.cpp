#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
#define ll long long
#define pb push_back
#define mo 1000000007
#define add(x,y) x=(x+(y))%mo;
using namespace std;
int n,m,p,x,y,ans;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	rep(i,1,n){
		scanf("%d",&x);
		ans+=(x-y)/p;
		scanf("%d",&y);y+=x;
	}ans+=(m-y)/p;
	printf("%d\n",ans);
}