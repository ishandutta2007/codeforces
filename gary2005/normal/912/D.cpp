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
int n,m,r,k,p[100000];
int calc(int now,int bound){
	int L,R;
	L=max(1,now-r+1);
	R=min(now,bound-r+1);
	return R-L+1;
}
vector<int> v1,v2;
bool cmp(int A,int B){
	return A>B;
}
priority_queue<pair<LL,int> >  q;/*value index*/
int s1,s2;
LL res=0;
int main(){
//	fastio;
	cin>>n>>m>>r>>k;
	rb(i,1,n) v1.PB(calc(i,n));
	rb(i,1,m) v2.PB(calc(i,m));
	sort(ALL(v1),cmp),sort(ALL(v2),cmp);
	s1=v1.size(),s2=v2.size();
	rep(i,s1){
		q.push(II(v1[i]*v2[0],i));
	}
	rb(i,1,k){
		mp now=q.top();
		q.pop();
		if(p[now.SEC]+1<s2)
		q.push(II((LL)v1[now.SEC]*v2[++p[now.SEC]],now.SEC));
		res+=now.FIR;
//		cout<<now.SEC<<" "<<s1<<" "<<now.FIR<<endl;
	}
	LL all=(LL)(n-r+1)*(LL)(m-r+1);
//	cout<<res<<" "<<all<<endl;
//	cout<<calc(2,3)<<endl;
	printf("%.16f\n",(double)(res)/double(all));
	return 0;
}