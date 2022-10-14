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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,q;
const int MAXN=1000000+2;
struct BIT{
	int bit[MAXN+10]={0},n;
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}b;
int main(){
	fastio;
	cin>>n>>q;
	b.n=n;
	rb(i,1,n)
	{
		int ai;
		cin>>ai;
		b.add(ai);
	}
	rb(i,1,q){
		int ki;
		cin>>ki;
		if(ki<0){
			ki=-ki;
			int l=0,r=n;
			if(ki==1&&b.sum(1)>=1){
				b.add(1,-1);
				continue;
			}
			while(l<r-1){
				int mid=(l+r)>>1;
				if(b.sum(mid)>=ki){
					r=mid;
				}
				else{
					l=mid;
				}
			}
//			cout<<b.sum(n)<<endl;
			b.add(r,-1);
		}
		else{
			b.add(ki,1);
		}
	}
	int res=0;
	rb(i,1,n){
		if(b.query(i,i)>=1){
			res=i;
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}