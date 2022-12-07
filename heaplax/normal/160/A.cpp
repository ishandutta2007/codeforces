#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n,a[101],p,t,ans;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		t+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; p<=t; ans++,i++)
		p+=a[i],t-=a[i];
	printf("%d\n",ans);
}