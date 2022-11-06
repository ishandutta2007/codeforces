#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
int main(){int n;
	scanf("%d",&n);
	rep(i,2,n){
		while(!(n%i)){
			printf("%d",i);n/=i;
		}
	}
}