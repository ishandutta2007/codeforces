#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;/*
void my_assert(bool x){
	printf("NO\n");
	return 0;
}*/
int main(){
	int n;
	scanf("%d",&n);
	int b[150000];
	vector<int> v;
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(b[i])
		v.pb(b[i]);
	}/*
	if(v.size()==1){
		printf("NO\n");
		return 0;
	}
	else if(v.size()==2&&v[0]==v[1]){
		printf("NO\n");
		return 0;
	}*/
	LL a[150000];
	LL x=1e9;
	if(b[0]>b[n-1]){
		a[n-1]=b[0]*x+b[n-1];
		for(int i=n-2;i>0;i--){
			a[i]=b[i]+a[i+1];
		}
		a[0]=b[0];
	}
	else{
		int ok=0;
		for(int i=0;i<n;i++){
			if(b[i]<b[i+1]){
				ok=1;
				a[i+1]=b[i+1];
				a[i]=b[i+1]*x+b[i];
				for(int j=i-1;j>=0;j--){
					a[j]=a[j+1]+b[j];
				}
				//a[n-1]=a[0]+b[n-1];
				for(int j=n-1;j>i+1;j--){
					a[j]=a[(j+1)%n]+b[j];
				}
				break;
			}
		}
		if(!ok){
			if(b[0]==0)
			{
				printf("YES\n");
				for(int i=0;i<n;i++)
				printf("1 ");
				printf("\n");
			}
			else
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=0;i<n;i++){
		printf("%lld ",a[i]);
	}
	printf("\n");
}