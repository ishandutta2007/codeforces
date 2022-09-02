#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int num[100005];
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("1");
		return 0;
	}
	if(n%4==2 || n%4==3){
		puts("-1");
		return 0;
	}
	int v1=2,v2=n,v3=1,v4=n-1;
	int s1=1,s2=2,s3=n-1,s4=n;
	if(n%2==0){
	while(s3>=s2){
		num[s1]=v1;
		num[s2]=v2;
		num[s3]=v3;
		num[s4]=v4;
		s1+=2;
		s2+=2;
		s3-=2;
		s4-=2;
		v1+=2;
		v2-=2;
		v3+=2;
		v4-=2;
	}
	}else{
	while(s3>=s2){
		num[s1]=v1;
		num[s2]=v2;
		num[s3]=v3;
		num[s4]=v4;
		s1+=2;
		s2+=2;
		s3-=2;
		s4-=2;
		v1+=2;
		v2-=2;
		v3+=2;
		v4-=2;
	}
	num[(n+1)/2]=(n+1)/2;
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",num[i],i==n?'\n':' ');
	}
}