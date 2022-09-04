#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	int i,j;
	for(i=1;i<n;i++)
	if(a[i]!=a[i-1])
	break;
	for(j=n-2;j>=0;j--)
	if(a[j]!=a[j+1])
	break;
	if(j<i)
	printf("0\n");
	else
	printf("%d\n",j-i+1);
}