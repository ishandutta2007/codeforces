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
	int n;
	scanf("%d",&n);
	char a[1005],b[1005];
	int num[2][10];
	int num1[2][10];
	memset(num,0,sizeof(num));
		memset(num1,0,sizeof(num1));
	scanf("%s %s",a,b);
	for(int i=0;i<n;i++)
	{
		num[0][a[i]-'0']++;
		num1[0][a[i]-'0']++;
		num[1][b[i]-'0']++;
		num1[1][b[i]-'0']++;
	}
	int ans=0;
	for(int i=9;i>0;i--){
		if(num[0][i]>num[1][i]){
			ans+=num[0][i]-num[1][i];
		}
		else{
			num[1][i-1]+=num[1][i]-num[0][i];
		}
	}
	printf("%d\n",ans);
	ans=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<10;j++)
			num[i][j]=num1[i][j];
	for(int i=9;i>0;i--){
		if(num[0][i-1]>num[1][i]){
			ans+=num[1][i];
		}
		else{
			ans+=num[0][i-1];
			num[1][i-1]+=num[1][i]-num[0][i-1];
		}
	}
	printf("%d\n",ans);
}