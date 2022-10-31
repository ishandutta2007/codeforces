#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[210000];
int d[210000];
int z[210000];
int sum[210000];
int main(){
	int a,b;scanf("%d%d",&a,&b);b--;
	if(a==1){
		printf("0\n");return 0;
	}
	for(int i=0;i<a;i++)scanf("%d",c+i);
	int ba=0;
	int f=0;
	for(int i=0;i<a;i++){
		if(b==i&&c[i]){
			ba++;
		}else if(b!=i&&c[i]==0){
			//ba++;
			f++;
		}else{
			d[c[i]]++;
		}
	}
	int ret=88888888;
	for(int i=1;i<a;i++){
		z[i]=z[i-1];
		if(!d[i])z[i]++;
	}
	for(int i=a-1;i>0;i--){
		sum[i]=sum[i+1]+d[i];
	}
	for(int i=1;i<a;i++){
		int t=f+sum[i+1];
		int tot=max(t,z[i]);
		ret=min(ret,ba+tot);
	}
	printf("%d\n",ret);
}