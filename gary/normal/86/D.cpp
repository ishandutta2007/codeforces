/*
AuThOr GaRyMr
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int magic=600;
int n,t,a[200000+10];
LL ans[200000+10],cnt[1000000+10];
pair<mp,int> queries[200000+10];
bool cmp(pair<mp,int> A,pair<mp,int > B){
	if(A.FIR.FIR/magic!=B.FIR.FIR/magic)
		return A.FIR.FIR/magic<B.FIR.FIR/magic;
	return A.FIR.SEC<B.FIR.SEC;
}
int main(){
	fastio;
	cin>>n>>t;
	rb(i,1,n)
		cin>>a[i];
	rb(i,1,t){
		cin>>queries[i].FIR.FIR>>queries[i].FIR.SEC;
		queries[i].SEC=i;
	}
	sort(queries+1,queries+1+t,cmp);
	LL cur=0;
	int  l=0,r=0;
	rb(i,1,t){
		while(l<queries[i].FIR.FIR){
			cur-=cnt[a[l]]*cnt[a[l]]*a[l];
			cnt[a[l]]--;
			cur+=cnt[a[l]]*cnt[a[l]]*a[l];
			++l;
		}
		while(l>queries[i].FIR.FIR){l--;
			cur-=cnt[a[l]]*cnt[a[l]]*a[l];
			cnt[a[l]]++;
			cur+=cnt[a[l]]*cnt[a[l]]*a[l];
			
		}
		while(r<queries[i].FIR.SEC){r++;
			cur-=cnt[a[r]]*cnt[a[r]]*a[r];
			cnt[a[r]]++;
			cur+=cnt[a[r]]*cnt[a[r]]*a[r];
			
		} 
		while(r>queries[i].FIR.SEC){
			cur-=cnt[a[r]]*cnt[a[r]]*a[r];
			cnt[a[r]]--;
			cur+=cnt[a[r]]*cnt[a[r]]*a[r];
			r--;
		}
//		cout<<l<<" "<<r<<" "<<cnt[a[r]]<<" "<<cur<<endl;
		ans[queries[i].SEC]=cur;
	}
	rb(i,1,t)
		cout<<ans[i]<<endl;
	return 0;
}