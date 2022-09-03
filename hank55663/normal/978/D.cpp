#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	int a[100005];
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans=1e9;
	for(int st=a[0]-1;st<=a[0]+1;st++){
		for(int d=a[1]-st-1;d<=a[1]-st+1;d++){
			int sum=0;
			int ok=1;
			for(int i=0;i<n;i++){
				if(a[i]==st+d*i);
				else if(abs(a[i]-(st+d*i))==1)sum++;
				else{
					ok=0;
					break;
				}
			}
			//printf("%d %d %d %d\n",st,d,sum,ok);
			if(ok){
				ans=min(ans,sum);
			}
		}
	}
	if(ans==1e9)ans=-1;
	printf("%d\n",ans);
}