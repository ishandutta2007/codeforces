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
int n,l,r,x,a[N];char sh[3];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",sh);scanf("%d",&x);
		if(i==1)continue;
		if(sh[0]=='L'){
			l--;a[x]=l;
		}else if(sh[0]=='R'){
			r++;a[x]=r;
		}else{
			printf("%d\n",min(a[x]-l,r-a[x]));
		}
	}
}