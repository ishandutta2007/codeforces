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
typedef complex<double> C;
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=5){
		printf("-1\n");
	}
	else{
		printf("1 2\n");
		for(int i = 3;i<=n;i++){
			if(i&1)
			printf("1 %d\n",i);
			else
			printf("2 %d\n",i);
		}
	}
	for(int i = 1;i<n;i++)
	printf("%d %d\n",i,i+1);
}