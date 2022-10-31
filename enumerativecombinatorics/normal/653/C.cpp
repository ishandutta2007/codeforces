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
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[200000];
int x[210000];
int at[210000];
int n;
int chk(int a,int b){
	if(a>b)swap(a,b);
	if(a+1==b){
		if(a%2==0){
			if(a&&p[a-1]<=p[b])return 0;
			if(p[b]>=p[a])return 0;
			if(b<n-1&&p[a]<=p[b+1])return 0;
		}else{
			if(a&&p[a-1]>=p[b])return 0;
			if(p[b]<=p[a])return 0;
			if(b<n-1&&p[a]>=p[b+1])return 0;
		}
	}else{
		if(a%2==0){
			if(a&&p[a-1]<=p[b])return 0;
			if(a<n-1&&p[b]>=p[a+1])return 0;
		}else{
			if(a&&p[a-1]>=p[b])return 0;
			if(a<n-1&&p[b]<=p[a+1])return 0;
		}
		if(b%2==0){
			if(b&&p[b-1]<=p[a])return 0;
			if(b<n-1&&p[a]>=p[b+1])return 0;
		}else{
			if(b&&p[b-1]>=p[a])return 0;
			if(b<n-1&&p[a]<=p[b+1])return 0;
		}
	}
	if(x[a+1]&&b!=a+1&&b!=a+2)return 0;
	if(x[b+1])return 0;
//	printf("%d %d\n",a,b);
	return 1;
}
int main(){
	int a;scanf("%d",&a);
	n=a;
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	for(int i=0;i<a-1;i++){
		if(i%2==0){
			if(p[i]>=p[i+1])x[i]=1;
		}else{
			if(p[i]<=p[i+1])x[i]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<a-1;i++){
		if(x[i]){
			at[cnt]=i;
			cnt++;
			if(x[i+1])i++;
		}
	}
	if(cnt>2){
		printf("0\n");return 0;
	}
	int ret=0;
	if(cnt==2){
		if(chk(at[0],at[1]))ret++;
		if(chk(at[0]+1,at[1]))ret++;
		if(chk(at[0],at[1]+1))ret++;
		if(chk(at[0]+1,at[1]+1))ret++;
	}else{
		if(chk(at[0],at[0]+1))ret++;
		for(int i=0;i<a;i++){
			if(i==at[0]||i==at[0]+1)continue;
			if(chk(at[0],i))ret++;
			if(chk(at[0]+1,i))ret++;
		}

	}
	printf("%d\n",ret);
}