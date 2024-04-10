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
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	s=s+'0';
	int last=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			printf("%d",last);
			last=0
		;} 
		else{
			last++;
		}
	}
}