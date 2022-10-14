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
bool on[1002],need[1002];
int n,m;
void query(vector<int> v){
//	cerr<<"?";
	cout<<v.size()<<" ";
	for(auto it: v){
		on[it]=1;
		cout<<it<<" ";
	}
	cout<<endl;
	ff;
	int pos;
	cin>>pos;
	rb(i,1,v.size()){
		on[(pos+i-1)%n ? (pos+i-1)%n:n]=0;
//		cout<<((pos+i-1)%n ? (pos+i-1)%n:n)<<endl;
	}
}
int main(){
	fastio;
	cin>>n;
	if(n<=3){
		cout<<0<<endl;
		ff;
		return 0;
	}
	int best=-INF;
	rb(i,1,n){
		rb(j,1,n)
			need[j]=0;
		for(int j=1,cnt=1;j<=n;j++,cnt++){
			if(cnt==i+1){
				cnt=0;
				continue;
			}
			need[j]=1;
		}
		need[n]=0;
		int tmp=0;
		rb(j,1,n)
			tmp+=need[j];
		if(tmp>best+i){
			best=tmp-i;
			m=i;
		}
	}	
//	cout<<m<<" "<<best<<endl;
	rb(j,1,n)
		need[j]=0;
	for(int j=1,cnt=1;j<=n;j++,cnt++){
		if(cnt==m+1){
			cnt=0;
			continue;
		}
		need[j]=1;
	}
	need[n]=0;
	while(1){
		vector<int> que;
		rb(i,1,n){
			if(need[i]&&!on[i]){
				que.PB(i);
				if(que.size()==m+1) break;
			}
		}
//		cout<<que.size()<<endl;
		if(que.size()<=1) break;
		query(que);
		bool ok=1;
		rb(i,1,n){
			if(need[i]){
				if(i>que[que.size()-1]) ok=0;
			}
		}
		if(ok){
			break;
		}
	}
	cout<<0<<endl;
	return 0;
}