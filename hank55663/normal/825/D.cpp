#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
//#define pi 3.14159265359
#define rank Rank
using namespace std;
typedef long long LL;
int mod=1e9+7;
char s[1000005],t[1000005];
char ans[1000005];
int main()
{	

	scanf("%s",s);
	scanf("%s",t);
	int counts[26],countt[26],counth=0;
	MEM(counts);
	MEM(countt);
	int slen=strlen(s),tlen=strlen(t);
	for(int i=0;i<slen;i++){
		if(s[i]!='?')
		counts[s[i]-'a']++;
		else
		counth++;
	}
	for(int i=0;i<tlen;i++){
		countt[t[i]-'a']++;
	}
	LL Max=1e6+1,Min=0;
	while(Max>Min+1){
		LL mid=(Max+Min)/2; 
		LL count=0;
		for(int i=0;i<26;i++){
			count+=max(countt[i]*mid-counts[i],0ll);
		}
	//	printf("%d %d %d\n",mid,count,counth);
		if(count>counth)
		Max=mid;
		else
		Min=mid;
	}

	int anssize=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<countt[i]*Min-counts[i];j++)
		{
			ans[anssize++]='a'+i;
		//	printf("%d",j);
		}
	}
	int index=0;
	for(int i=0;i<slen;i++){
		if(s[i]=='?'){
			if(index>=anssize)
			printf("a");
			else
			printf("%c",ans[index++]);
		} 
		else
		printf("%c",s[i]);
	}
}