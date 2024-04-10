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
int UF[210000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);
	if(a>b)swap(a,b);
	if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int p[110000];
int q[110000];
char in[110000];
int ans[110000];
int cnt[210000];
int use[210000];

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		scanf("%d%d",p+i,q+i);p[i]--;q[i]--;
		scanf("%s",in+i);
	}
	int ret=mod;
	for(int t=0;t<2;t++){
		for(int i=0;i<a*2;i++)UF[i]=-1;

		for(int i=0;i<b;i++){
			if(in[i]=='B'){
				UNION(p[i]*2,q[i]*2);
				UNION(p[i]*2+1,q[i]*2+1);
			}else{
				UNION(p[i]*2,q[i]*2+1);
				UNION(p[i]*2+1,q[i]*2);
			}
		}
		bool dame=false;
		for(int i=0;i<a;i++){
			if(FIND(i*2)==FIND(i*2+1))dame=true;
		}
		if(!dame){
			for(int i=0;i<a*2;i++)cnt[i]=use[i]=0;
			for(int i=0;i<a;i++){
				cnt[FIND(i*2)]++;
			}
			int tmp=0;
			for(int i=0;i<a;i++){
				if(cnt[i*2]>cnt[i*2+1]){
					use[i*2+1]=1;
				}else use[i*2]=1;
				tmp+=min(cnt[i*2],cnt[i*2+1]);
			}
			if(tmp<ret){
				ret=tmp;
				int ind=0;
				for(int i=0;i<a;i++){
					if(use[FIND(i*2)])ans[ind++]=i;
				}
			}
		}
		for(int i=0;i<b;i++){
			if(in[i]=='B')in[i]='R';
			else in[i]='B';
		}
	}

	// output
	if(ret==mod){
		printf("-1\n");return 0;
	}
	printf("%d\n",ret);
	for(int i=0;i<ret;i++){
		if(i)printf(" ");
		printf("%d",ans[i]+1);
	}printf("\n");
}