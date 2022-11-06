#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 300000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,x,y,nw,ans;
int main(){
	scanf("%d",&n);nw=1;
	rep(i,1,n+1){
		if(i>n)x=1001;else scanf("%d",&x);
		if(x-y==1)nw++;else{
			ans=max(ans,nw);nw=1;
		}y=x;
	}
	printf("%d\n",max(max(ans,nw)-2,0));
}