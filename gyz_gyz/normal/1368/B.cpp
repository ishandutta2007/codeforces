#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll>pil;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
char u[]="codeforces";
ll a[10];
int main(){ll n,tot=1;
	scanf("%lld",&n);int nw=0;
	rep(i,0,9)a[i]=1;
	while(tot<n){
		tot/=a[nw];tot*=++a[nw];
		nw=(nw+1)%10;
	}
	rep(i,0,9)rep(j,1,a[i])printf("%c",u[i]);
}