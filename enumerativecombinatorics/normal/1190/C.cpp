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
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
char in[110000];
vector<int>ind[2];
int cnt(int L,int R,int t){
	if(R<L)return 0;
	return upper_bound(ind[t].begin(),ind[t].end(),R)-lower_bound(ind[t].begin(),ind[t].end(),L);
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",in);
	int ret=0;
	for(int i=0;i<a;i++){
		ind[in[i]-'0'].push_back(i);
	}
	for(int i=0;i<=a-b;i++){
		int c0=cnt(0,i-1,0)+cnt(i+b,a-1,0);
		int c1=cnt(0,i-1,1)+cnt(i+b,a-1,1);
		if(c0==0||c1==0){
			ret=2;break;
		}
		int l0=ind[0][0];
		int l1=ind[1][0];
		int r0=ind[0][ind[0].size()-1];
		int r1=ind[1][ind[1].size()-1];
		if(i<=l0&&l0<i+b){
			l0=*(lower_bound(ind[0].begin(),ind[0].end(),i+b));	
		}
		if(i<=l1&&l1<i+b){
			l1=*(lower_bound(ind[1].begin(),ind[1].end(),i+b));	
		}
		if(i<=r0&&r0<i+b){
			r0=*(lower_bound(ind[0].begin(),ind[0].end(),i)-1);
		}
		if(i<=r1&&r1<i+b){
			r1=*(lower_bound(ind[1].begin(),ind[1].end(),i)-1);
		}
		if(r0-l0>=b||r1-l1>=b){
			ret=1;
		}
	}
	if(ret==0)printf("quailty\n");
	else if(ret==1)printf("once again\n");
	else printf("tokitsukaze\n");
}