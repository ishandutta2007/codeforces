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
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}

char c[510000];
int n;
int sa_k;
int Rank[510000];
int tmp[510000];
int sa[510000];
int lcp[510000];
bool compare_sa(int i,int j){
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	else{
		int ri=i+sa_k<=n?Rank[i+sa_k]:-1;
		int rj=j+sa_k<=n?Rank[j+sa_k]:-1;
		return ri<rj;
	}
}
void construct_sa(){
	for(int i=0;i<=n;i++){
		sa[i]=i;
		Rank[i]=i<n?c[i]:-1;
	}
	for(sa_k=1;sa_k<=n;sa_k*=2){
		sort(sa,sa+n+1,compare_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++){
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
		}
		for(int i=0;i<=n;i++){
			Rank[i]=tmp[i];
		}
	}
}

void construct_lcp(){
	for(int i=0;i<=n;i++)Rank[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(int i=0;i<n;i++){
		int j=sa[Rank[i]-1];
		if(h>0)h--;
		for(;j+h<n&&i+h<n;h++){
			if(c[j+h]!=c[i+h])break;
		}
		lcp[Rank[i]-1]=h;
	}
}
int pos[510000];
vector<int>dep[1010000];
int to[510000];
int segtree[1048576*2];
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return mod;
	if(c<=a&&b<=d)return segtree[e];
	return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
	a+=524288*2;
	while(a){
		segtree[a]=min(segtree[a],b);
		a/=2;
	}
}
int S=500100;
int main(){
	int a;scanf("%d",&a);
	scanf("%s",c);
	n=a;
	construct_sa();
	construct_lcp();
	int cur=0;
	for(int i=0;i<a;i++){
		if(c[i]=='(')cur++;
		else cur--;
		pos[i+1]=cur;
	}
	for(int i=0;i<=a;i++){
		dep[pos[i]+S].push_back(i);
	}
	for(int i=0;i<1048576*2;i++)segtree[i]=a+1;
	for(int i=a;i>=0;i--){
		to[i]=query(0,1048575,0,pos[i]+S-1,1);
		update(pos[i]+S,i);
	}

	long long ret=0;
	for(int i=0;i<=a;i++){
		int at=sa[i];
		int cnt=upper_bound(dep[pos[at]+S].begin(),dep[pos[at]+S].end(),to[at]-1)-lower_bound(dep[pos[at]+S].begin(),dep[pos[at]+S].end(),at+(i?lcp[i-1]:0)+1);
		if(cnt<0)cnt=0;
		ret+=cnt;
	//	printf("%d %d %d %d %d: ",sa[i],lcp[i],at+(i?lcp[i-1]:0)+1,to[at]-1,cnt);
	//	for(int j=sa[i];c[j];j++){
	//		printf("%c",c[j]);
	//	}printf("\n");
	}

	printf("%I64d\n",ret);
}