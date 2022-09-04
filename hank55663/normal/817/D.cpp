#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define right RRR
#define left LLL
using namespace std;
typedef long long LL;
	int right[1000006],left[1000006];
		int a[1000000];
int main(){	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	vector<pii> v;
	v.pb(mp(a[0],0));
	for(int i=1;i<n;i++){
		while(!v.empty()){
			if(v.back().x>=a[i])
			break;
			right[v.back().y]=i;
			v.pop_back();
		}
		v.pb(mp(a[i],i));
	}
	while(!v.empty()){
		right[v.back().y]=n;
		v.pop_back();
	}
	v.pb(mp(a[n-1],n-1));
	for(int i=n-2;i>=0;i--){
		while(!v.empty()){
			if(v.back().x>a[i])
			break;
			left[v.back().y]=i;
			v.pop_back();
		}
		v.pb(mp(a[i],i));
	}
	while(!v.empty()){
		left[v.back().y]=-1;
		v.pop_back();
	}
	LL ans=0;
	for(int i=0;i<n;i++){
		ans+=(LL)a[i]*(i-left[i])*(right[i]-i);
	}
//	printf("%I64d\n",ans);
	v.pb(mp(a[0],0));
	for(int i=1;i<n;i++){
		while(!v.empty()){
			if(v.back().x<=a[i])
			break;
			right[v.back().y]=i;
			v.pop_back();
		}
		v.pb(mp(a[i],i));
	}
	while(!v.empty()){
		right[v.back().y]=n;
		v.pop_back();
	}
	v.pb(mp(a[n-1],n-1));
	for(int i=n-2;i>=0;i--){
		while(!v.empty()){
			if(v.back().x<a[i])
			break;
			left[v.back().y]=i;
			v.pop_back();
		}
		v.pb(mp(a[i],i));
	}
	while(!v.empty()){
		left[v.back().y]=-1;
		v.pop_back();
	}
	for(int i=0;i<n;i++){
		//printf("%d %d\n",left[i],right[i]);
		ans-=(LL)a[i]*(i-left[i])*(right[i]-i);
	}
	printf("%I64d\n",ans);
}