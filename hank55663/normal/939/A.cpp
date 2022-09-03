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
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
int main(){
	int n;
	scanf("%d",&n);
	int f[5005];
	for(int i = 1;i<=n;i++)
		scanf("%d",&f[i]);
	for(int i =1;i<=n;i++){
		if(f[f[f[i]]]==i){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}