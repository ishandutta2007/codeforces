#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i =1;i<n;i++)
		if(n%i==0)cnt++;
	printf("%d\n",cnt);
}