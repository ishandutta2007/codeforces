#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[300005];
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	int Max=m,Min=-1;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		int last = 0;
		int ok=1;
		for(int i = 0;i<n;i++){
			if(a[i]+mid>=m+last){
				continue;
			}
			else{
				if(a[i]+mid<last){
					ok=0;
					break;
				}
				else{
					last=max(a[i],last);
				}
			}
		}
		if(!ok){
			Min=mid;
		}
		else{
			Max=mid;
		}
	}
	printf("%d\n",Max);
}