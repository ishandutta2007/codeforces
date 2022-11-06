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
const int N=2e5+10;
const ll inf=2e18;
pii a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i].fr);a[i].sc=i;
	}
	sort(a+1,a+n+1);int x=1,nw=2;
	rep(i,3,n)if(a[1].fr+(a[2].fr-a[1].fr)*nw!=a[i].fr){
		if(x==1)x=i;else x=0;
	}else ++nw;
	if(x)return printf("%d\n",a[x].sc),0;x=0;nw=2;
	rep(i,4,n)if(a[2].fr+(a[3].fr-a[2].fr)*nw!=a[i].fr)x=1;else ++nw;
	if(!x)return printf("%d\n",a[1].sc),0;x=0;nw=2;
	rep(i,4,n)if(a[1].fr+(a[3].fr-a[1].fr)*nw!=a[i].fr)x=1;else ++nw;
	if(!x)return printf("%d\n",a[2].sc),0;
	printf("-1\n");
}