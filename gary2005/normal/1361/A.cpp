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
int n,m;
vector<int> each[500000+20]; 
int E[500000+20],p[500000+20];
bool cmp(int A,int B){
	return E[A]<E[B];
}
int main(){
	fastio;
	cin>>n>>m;
	rb(i,1,n) 
		p[i]=i;
	
	rb(i,1,m){
		int a,b;
		cin>>a>>b;
		each[a].PB(b);
		each[b].PB(a);
	}
	rb(i,1,n)
	cin>>E[i];
	rb(i,1,n){
		sort(ALL(each[i]),cmp);
	}
	sort(p+1,p+1+n,cmp);
	rb(i,1,n){
		int is=1;
		for(auto it:each[p[i]]){
//			cout<<it<<endl;
			if(E[it]==is){
				is++;
			}
		}
//		cout<<is<<endl;
//		cout<<E[p[i]]<<endl;
		if(is==E[p[i]]){
			
		}
		else{
//			cout<<i<<endl;
			cout<<-1<<endl;
			return 0;
		}
	}
	rb(i,1,n)
	cout<<p[i]<<" ";
	return 0;
}