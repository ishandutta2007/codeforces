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
int b[110];
long long gcd(long long a,long long b){
	while(a){
		b%=a;swap(a,b);
	}
	return b;
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
int v[110];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)b[i]--;
	long long ret=1;
	for(int i=0;i<a;i++){
		if(v[i])continue;
		int at=i;
		v[at]=1;
		int cnt=0;
		while(1){
			at=b[at];
			cnt++;
			if(v[at]){
				if(at==i)break;
				else{
					printf("-1\n");return 0;
				}
			}
			v[at]=1;
		}
		if(cnt%2==0)cnt/=2;
		ret=lcm(ret,cnt);
	}
	printf("%I64d\n",ret);
}