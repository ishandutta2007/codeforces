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
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	n%=6;
	int a[3];
	memset(a,0,sizeof(a));
	a[x]=1;
	while(n--){
		if(n%2==0)
		swap(a[0],a[1]);
		else
		swap(a[1],a[2])
	;}
	for(int i=0;i<3;i++)
	if(a[i])
	printf("%d\n",i);
}