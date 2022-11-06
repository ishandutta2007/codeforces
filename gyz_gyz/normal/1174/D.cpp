#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
bool v[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	if(m>=(1<<n)){
		printf("%d\n",(1<<n)-1);
		rep(i,1,(1<<n)-1)printf("%d ",i^(i-1));
	}else{
		printf("%d\n",(1<<(n-1))-1);
		v[0]=v[m]=1;int ls=0;
		rep(i,1,(1<<n)-1)if(!v[i]){
			v[i]=v[i^m]=1;
			printf("%d ",ls^i);ls=i;
		}
	}
}