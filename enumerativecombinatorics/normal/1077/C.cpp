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
const long long mod=924844033;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int z[210000];
int p[210000];

int main(){
	int a;scanf("%d",&a);
	long long sum=0;
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
		sum+=p[i];
		z[i]=p[i];
	}
	std::sort(z,z+a);
	vector<int>ans;
	for(int i=0;i<a;i++){
		long long S=sum-p[i];
		int mm=z[a-1];
		if(z[a-1]==p[i])mm=z[a-2];
		if(S==mm*2)ans.push_back(i+1);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}printf("\n");
}