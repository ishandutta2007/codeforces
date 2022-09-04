#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int head[200005];
	map<int,int> next;
	next.clear();
	set<int> s;
	int n;
	scanf("%d",&n);
	int index=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(s.lower_bound(a)==s.begin()){
			head[index++]=a;
			s.insert(a);
		} 
		else{
			set<int> ::iterator it=s.lower_bound(a);
			it--;
			next[*it]=a;
			s.erase(it);
			s.insert(a); 
		}
	}
	for(int i=0;i<index;i++){
		int x=head[i];
		printf("%d",x);
		while(next[x]!=0){
			x=next[x];
			printf(" %d",x);
		}
		printf("\n");
	} 
}