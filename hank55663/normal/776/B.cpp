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
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int isPrime[100005];
int main(){
	for(int i=0;i<100005;i++)
	isPrime[i]=1;
	for(int i=2;i<100005;i++)
	if(isPrime[i]==1)
		for(int j=i*2;j<100005;j+=i)
			isPrime[j]=2;
	int n;
	scanf("%d",&n);
	if(n<=2)
	printf("1\n");
	else
	printf("2\n");
	printf("1");
	for(int i=3;i<=n+1;i++)
	printf(" %d",isPrime[i]);
	printf("\n");
}