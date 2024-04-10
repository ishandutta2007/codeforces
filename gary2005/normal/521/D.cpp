/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int k,n,m; 
const int MAXN=1e5+20;
vector<mp> as[MAXN],ad[MAXN];
vector<pair<double,int> > mu;
int a[MAXN],ty[MAXN];
double best,tmpanswer;
deque<int> TMP;
deque<int> answer;
bool cmp(int A,int B){
	return ty[A]<ty[B];
}
void Assign(){
	if(best>tmpanswer) return;
	answer=TMP;
	best=tmpanswer;
}
int main(){
	scanf("%d%d%d",&k,&n,&m);
	rb(i,1,k) scanf("%d",&a[i]);
	rb(i,1,n){
		int ti,ii,bi;
		scanf("%d%d%d",&ti,&ii,&bi);
		ty[i]=ti;
		if(ti==1) as[ii].PB(II(bi,i));
		else if(ti==2) ad[ii].PB(II(bi,i));
		else mu.PB(II(log(double(bi)),i));
	}
	best=-1;
	tmpanswer=0.0;
	sort(ALL(mu));
	reverse(ALL(mu));
	rb(i,1,k) sort(ALL(as[i])),reverse(ALL(as[i]));
	priority_queue<pair<double,int> > pq;
	rb(i,1,k){
		if(!as[i].empty()&&as[i][0].FIR>a[i]) ad[i].PB(II(as[i][0].FIR-a[i],as[i][0].SEC));sort(ALL(ad[i]));
		reverse(ALL(ad[i]));
		tmpanswer+=log(double(a[i]));
		LL sum=a[i];
		for(auto it:ad[i]){
			pq.push(II(log(double(sum+it.FIR))-log(double(sum)),it.SEC));
			sum+=it.FIR;
		}
	}
	if(pq.size()+mu.size()<=m){
		while(!pq.empty()) answer.PB(pq.top().SEC),pq.pop();
		for(auto it:mu) answer.PB(it.SEC);
	}
	else{
	while(m>mu.size()){
		TMP.push_front(pq.top().SEC);
		tmpanswer+=pq.top().FIR;
		pq.pop();
		--m;
	}
	double M=0.0;
	rep(i,m) M+=mu[i].FIR;
	rep(i,m) TMP.PB(mu[i].SEC);
	rl(i,m-1,0){
		tmpanswer+=M;
		Assign();
		tmpanswer-=M;
		if(pq.empty()) break;
		TMP.POB();
		TMP.push_front(pq.top().SEC);
		tmpanswer+=pq.top().FIR;
		pq.pop();
		M-=mu[i].FIR;
	}
	Assign();
	}
	sort(ALL(answer),cmp);
	cout<<answer.size()<<endl;
	for(auto it:answer) printf("%d ",it);
	return 0;
}