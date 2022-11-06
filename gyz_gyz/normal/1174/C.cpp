#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N];
int main(){int n,tot=0;
	scanf("%d",&n);
	rep(i,2,n){
		if(!a[i]){++tot;
			rep(j,1,n/i)a[i*j]=tot;
		}
		printf("%d ",a[i]);
	}
}