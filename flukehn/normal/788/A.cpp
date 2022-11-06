#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;i--)
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
int n,a[N];
ll f[N],mi[N],mx[N];
int main(){
	n=rd();
	rep(i,1,n)a[i]=rd();
	rep(i,1,n-1)a[i]-=a[i+1];
	rep(i,1,n)a[i]=abs(a[i]);
	per(i,1,n)f[i]=f[i+1]+(i&1?-a[i]:a[i]);
	mi[n]=mx[n]=f[n];
	per(i,1,n-1){
		mi[i]=min(mi[i+1],f[i]);
		mx[i]=max(mx[i+1],f[i]);
	}
	ll ans=0;
	rep(i,1,n-1){
		ans=max(ans,(i%2==0?f[i]-mi[i]:-f[i]+mx[i]));
	}
	cout<<ans<<endl;
}