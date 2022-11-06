#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=998244353;
int a[N];bool v[N];
int main(){int n,x=1;
	scanf("%d",&n);
	rep(i,2,n){int xi,ix;
		printf("? %d %d\n",x,i);fflush(stdout);
		scanf("%d",&xi);
		printf("? %d %d\n",i,x);fflush(stdout);
		scanf("%d",&ix);
		if(xi>ix){
			a[x]=xi;v[xi]=1;x=i;
		}else{
			a[i]=ix;v[ix]=1;
		}
	}
	rep(i,1,n)if(!v[i])a[x]=i;
	printf("!");
	rep(i,1,n)printf(" %d",a[i]);
	printf("\n");fflush(stdout);
}