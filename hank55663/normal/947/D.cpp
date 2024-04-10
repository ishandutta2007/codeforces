#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	char c[100005];
	scanf("%s",c);
	int cnt[100005];
	int last[100005];
	cnt[0]=0;
	for(int i=0;c[i]!=0;i++){
		cnt[i+1]=cnt[i];
		if(c[i]!='A'){
			cnt[i+1]++;
		}
		else{
			last[i+1]=last[i]+1;
		}
	}
	char c2[100005];
	scanf("%s",c2);
	int cnt2[100005];
	int last2[100005];
	cnt2[0]=0;
	MEM(last2);
	for(int i=0;c2[i]!=0;i++){
		cnt2[i+1]=cnt2[i];
		if(c2[i]!='A'){
			cnt2[i+1]++;
		}
		else{
			last2[i+1]=last2[i]+1;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		//printf("%d %d\n",cnt[b]-cnt[a-1],cnt2[d]-cnt2[c-1]);
		int x=cnt[b]-cnt[a-1];
		int y=cnt2[d]-cnt2[c-1];
		int aa=min(last[b],b-a+1),ba=min(last2[d],d-c+1);
		if(aa<ba)
		printf("0");
		else if(x==0&&y!=0&&aa==ba)
		printf("0");
		else{
			aa-=ba;
			aa%=3;
			if(aa)
			x+=2;
			if(x>y)
			printf("0");
			else if((x&1)!=(y&1))
			printf("0");
			else
			printf("1");
		}
	}
}
/*
BC
ACC
AABC
CC
ABC
AACC*/