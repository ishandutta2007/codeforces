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
	char c[300005];
	scanf("%s",c);
	for(int i =0;c[i+1]!=0;i++){
		if(c[i]>c[i+1]){
			swap(c[i],c[i+1]);
			printf("YES\n%d %d\n",i+1,i+2);
			return 0;
		}
	}
	printf("NO\n");
}