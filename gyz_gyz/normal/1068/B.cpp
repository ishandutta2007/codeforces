#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
ll n;int ans;
int main(){
	scanf("%I64d",&n);
	rep(i,1,n){
		if(n/i<i)break;
		if(!(n%i)){ans++;
			if(n/i!=i)ans++;
		}
	}
	printf("%d\n",ans);
}