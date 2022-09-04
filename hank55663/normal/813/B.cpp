#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){	
	LL x,y,l,r;
	scanf("%I64d %I64d %I64d %I64d",&x,&y,&l,&r);
	set<LL> s;
	for(LL i=1;i<=r;i=i*x){
		for(LL j=1;i+j<=r;j=j*y){
			if(i+j>=l&&i+j<=r)
			s.insert(i+j);
			if((j*y)/y!=j)
			break;
		}
		if((i*x)/x!=i)
		break;
	}
	s.insert(l-1);
	s.insert(r+1);
	LL last=l;
	LL ans=0;
	for(set<LL>::iterator it=s.begin();it!=s.end();it++){
		ans=max(ans,*it-last-1);
		last=*it;
	}
	printf("%I64d\n",ans);
}