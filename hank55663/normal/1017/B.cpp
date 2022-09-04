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
	char c[100005],c2[100005];
	scanf("%s",c);
	scanf("%s",c2);
	LL one=0,zero=0,o1=0,z1=0;
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='0'){
			zero++;
			if(c2[i]=='0')
			z1++;
		}
		else{
			one++;
			if(c2[i]=='0')
			o1++;
		}
	}
	printf("%lld\n",o1*zero+z1*one-o1*z1);
}