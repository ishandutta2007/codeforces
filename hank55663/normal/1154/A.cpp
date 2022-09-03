#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int a[4];
	scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
	sort(a,a+4);
	printf("%d %d %d\n",a[3]-a[0],a[3]-a[1],a[3]-a[2]);
}