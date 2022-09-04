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
#define list List
using namespace std;
typedef long long LL;
int hi=(1<<19);
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	if(n==2&&x==0){
		printf("NO\n");
		return 0;
	}
	int ans=0;
	set<int> s;
	for(int i=1;i<n;i++){
		ans^=i;
		s.insert(i); 
	}
	if(s.find(ans^x)==s.end()){
		s.insert(ans^x);
		printf("YES\n");
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
		printf("%d ",*it);
	}
	else{
		ans^=x;
		s.erase(n-1);
		ans^=(n-1);
		if(ans==0){
			s.erase(n-2);
			s.insert(0);
			s.insert(hi+n-2);
			s.insert(hi);	
		}
		else{
			s.insert(hi);
			s.insert(hi+ans);
		}
			printf("YES\n");
		assert(s.size()==n);
		int y=0;
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
		printf("%d ",*it),y^=*it;
		//printf("%d",y);
	}
}