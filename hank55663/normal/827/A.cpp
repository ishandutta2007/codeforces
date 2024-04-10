#include<bits/stdc++.h>
#include<assert.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
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
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
string* v[2000005];
int main()
{
	int n;
	scanf("%d",&n);
	string *s;
	for(int i=0;i<2000005;i++)
	v[i]=NULL;
	int len=0;
	for(int i=0;i<n;i++){
		s=new string();
		cin>>*s;
		int t;
		scanf("%d",&t);
		while(t--){
			int k;
			scanf("%d",&k);
			if(v[k]==NULL||v[k]->size()<s->size())
			v[k]=s;
			len=max(len,(int)k+(int)s->size());
		}
	}
	int j=0;
	string* now=NULL;
	for(int i=1;i<len;i++){
	//	printf("%d",i);
		if(now==NULL&&v[i]==NULL)
		printf("a");
		else if(v[i]!=NULL){
			if(now==NULL||v[i]->size()>now->size()-j)
				now=v[i],j=0;
		}
		if(now!=NULL){
			printf("%c",(*now)[j++]);
			if(j>=now->size())
			now=NULL,j=0;
		}
	}
}
//dao@jisuanke.com
//0933460520
//8/13