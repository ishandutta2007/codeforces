#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
char a[100005];
int n,m,k;
int main(){
	scanf("%d%d%d%s",&n,&m,&k,a+1);
	for(int i=1,opt,l,r,x;i<=m+k;i++){
		scanf("%d%d%d%d",&opt,&l,&r,&x);
		if(opt==1)memset(a+l,x+'0',r-l+1);
		else puts(memcmp(a+l,a+l+x,r-l-x+1)?"NO":"YES");
	}
	return 0;
}