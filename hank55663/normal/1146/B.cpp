/*#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	/*char c[55];
	scanf("%s",c);
	int cnt=0;
	for(int i = 0;c[i]!=0;i++){
		if(c[i]=='a')
			cnt++;
	}
	int len=strlen(c);
	printf("%d\n",min(cnt*2-1,len));*/
    char c[100005];
	scanf("%s",c);
	char temp[100005];
	fill(temp,temp+100005,0);
	int now=0;
	for(int i = 0;c[i]!=0;i++){
		if(c[i]!='a')
		temp[now++]=c[i];
	}
	if(strlen(temp)%2){
		printf(":(\n");
	}
	else{
		int x=0,y=strlen(temp)/2;
		while(temp[y]!=0){
			if(temp[x]!=temp[y]){
				printf(":(\n");
				return 0;
			}
			x++,y++;
			//printf("%d %d\n",x,y);
		}
		int len=strlen(temp)/2;
		int xx=strlen(c);
		for(int i =xx-len;c[i]!=0;i++){
			if(c[i]=='a'){
				printf(":(\n");
				return 0;
			}
		}
		c[xx-len]=0;
		printf("%s\n",c);
	}
	return 0;
}