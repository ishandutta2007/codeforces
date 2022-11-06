#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=998244353;
int main(){int a[3],d;
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d);
	sort(a,a+3);printf("%d\n",max(0,d-a[1]+a[0])+max(0,d-a[2]+a[1]));
}