/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN = 200000+2;
const int MAGIC = 700;
int n,m;
vector<int> block[MAGIC];
int bn;
int a[MAXN];
int query(int l,int r,int num){
	int res=0;
	rb(i,l,r){
//		cout<<i<<" "<<l<<" "<<r<<endl;
		if(i%MAGIC==1){
			int b=i/MAGIC+1;
			while(b*MAGIC<=r){
				int tot=block[b].size();
				tot-=upper_bound(ALL(block[b]),num)-block[b].begin();
				res+=tot;
				b++;
			} 
			rb(j,(b-1)*MAGIC+1,r){
				res+=a[j]>num;
			}
			break;
		}
//		cout<<i<<endl;
		if(a[i]>num) res++;
	}
	return res;
}
int query2(int l,int r,int num){
	return r-l+1-query(l,r,num);
}
int main(){
	fastio;
	R2(n,m);
	bn=1;
	while((bn+1)*MAGIC<=n){
		bn++;
	}
	rb(i,1,n)
	{
		int be=(i-1)/MAGIC+1;
		block[be].PB(i);
		a[i]=i;
	}
	LL res=0;
	while(m--){
			int l,r;
			R2(l,r);
			if(l>r) swap(l,r);
			if(l!=r) {
				res+=(a[r]>a[l]? 1:-1);
			res+=query(l+1,r-1,a[l]);
			res-=query(l+1,r-1,a[r]);
			res+=query2(l+1,r-1,a[r]);
			res-=query2(l+1,r-1,a[l]);
			swap(a[l],a[r]);
			int b=(l-1)/MAGIC+1;
			block[b].clear();
			rb(i,(b-1)*MAGIC+1,b*MAGIC){
				if(i>n) break;
				block[b].PB(a[i]);
			}
			sort(ALL(block[b]));
			b=(r-1)/MAGIC+1;
			block[b].clear();
			rb(i,(b-1)*MAGIC+1,b*MAGIC){
				if(i>n) break;
				block[b].PB(a[i]);
			}
			sort(ALL(block[b]));
		}
		cout<<res<<endl;
	}
	return 0;
}