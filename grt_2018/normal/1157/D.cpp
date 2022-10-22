#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000;
int n,k;
int arr[nax];
LL sum;

int main() {
	scanf("%d%d",&n,&k);
	int p = 0,x=-1;
	for(int i=0; i<k;i++) {
		p+=(1<<i);
		if(p>=n) {
			x=1;
			break;
		}
	}
	if(x==-1) {
		x=(n-1)/p+1;
	}
	sum = (LL)x*k + (LL)k*(k-1)/2;
	arr[0]=x;
	for(int i=1; i<k;i++) {
		arr[i] = arr[i-1]+1;
		LL y = max((n-sum)/(k-i),(LL)0);
		LL zw = min((LL)arr[i-1]-1,y);
		sum+=zw*(k-i);
		arr[i]+=zw;
	}
	LL s=0;
	for(int i=0; i<k;i++) {
		s+=arr[i];
	}
	if(s==n) {
		printf("YES\n");
		for(int i=0; i<k;i++) {
			printf("%d ",arr[i]);
		}
	}
	else {
		printf("NO");
	}
}