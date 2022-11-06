#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,m;ll x,y,ans;char a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);y=1;
	scanf("%s",a);scanf("%s",b);
	rep(i,0,m-1)if(b[i]=='1')x++;
	rep(i,1,n){
		if(a[n-i]=='1'){
			ans=(ans+x*y)%mo;
		}
		y=y*2%mo;
		if(b[m-i]=='1')x--;
		if(!x)break;
	}
	printf("%I64d",ans);
}