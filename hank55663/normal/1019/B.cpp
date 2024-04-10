#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	if(n/2%2==1){
		printf("! -1\n");
		fflush(stdout);
	}
	else{
		int now=1,last=1+n/2;
		int a,b;
		printf("? %d\n",now);
		fflush(stdout);
		scanf("%d",&a);
		printf("? %d\n",last);
		fflush(stdout);
		scanf("%d",&b);
		if(a>b)
		swap(now,last);
		if(a==b){
			printf("! %d\n",now);
			fflush(stdout);
			return 0;
		}
		int Max=n/2,Min=0;
		while(1){
			int mid=(Max+Min)/2;
			printf("? %d\n",now+mid);
			fflush(stdout);
			scanf("%d",&a);
			printf("? %d\n",last+mid);
			fflush(stdout);
			scanf("%d",&b);
			if(a==b){
				printf("! %d\n",now+mid);
				fflush(stdout);
				return 0;
			}
			if(a<b){
				Min=mid;
			}
			else{
				Max=mid;
			}
		}
	}
}