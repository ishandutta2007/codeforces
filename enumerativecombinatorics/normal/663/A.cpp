#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-11;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
char in[20];
int ks[110];
int ans[110];
int main(){
	int sz=0;
	int cur=1;
	while(1){
		scanf("%s",in);
		scanf("%s",in);
		if(in[0]=='+'){
			ks[sz++]=cur;
			cur=1;
		}else if(in[0]=='-'){
			ks[sz++]=cur;
			cur=-1;
		}else{
			ks[sz++]=cur;
			break;
		}
	}
	int n;
	scanf("%d",&n);
	int A=0;
	int B=0;
	for(int i=0;i<sz;i++){
		if(ks[i]==1)A++;
		else B++;
	}
	if(A*n-B<n||A-B*n>n){
		printf("Impossible\n");return 0;
	}
	printf("Possible\n");
	int ca=A;
	int cb=B;
	while(ca-cb<n){
		ca++;
	}
	while(ca-cb>n){
		cb++;
	}
	int cnt=0;
	for(int i=0;i<sz;i++){
		if(ks[i]==1){
			ans[i]=(ca+A-1-cnt)/A;
			cnt++;
		}
	}
	cnt=0;
	for(int i=0;i<sz;i++){
		if(ks[i]==-1){
			ans[i]=(cb+B-1-cnt)/B;
			cnt++;
		}
	}
	for(int i=0;i<sz;i++){
		if(i){
			if(ks[i]>0)printf(" + ");
			else printf(" - ");
		}
		printf("%d",ans[i]);
	}
	printf(" = %d\n",n);
}