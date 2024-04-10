#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+100;
const int M=998244353;
int a[maxn],n,l,r;
int qry(int x){
	if (a[x]) return a[x];
	printf("? %d\n",x); fflush(stdout);
	scanf("%d",&a[x]);
	return a[x];
}
bool check(int x){
	bool ok=qry(x)<qry(x-1)&&qry(x)<qry(x+1);
	return ok;
}
int main(){
	cin >> n;
	a[0]=a[n+1]=n+1;
	l=0; r=n+1;
	while (r-l>1){
        int mid=(l+r)>>1;
        if (check(mid)){
			printf("! %d\n",mid);
			return 0;
        } else if (a[mid-1]<a[mid]){
			r=mid;
        } else {
			l=mid;
        }
	}
	assert(0);
	return 0;
}