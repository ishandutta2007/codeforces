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
priority_queue <mp> q;
int n;
struct speech{
	int sa,ea,sb,eb;
}each[100000+10];
bool cmp(speech A,speech B){
	return A.ea>B.ea;
}
int treen;
int seg_tree[8*200000+10],add_tree[8*200000+10];
int add(int now,int l,int r,int a,int b){
	if(r<=b&&l>=a) {
		add_tree[now]++;
		return seg_tree[now]+add_tree[now]; 
	}
	if(r<=a||l>=b){
		return seg_tree[now]+add_tree[now]; 
	}
	int mid=(l+r)>>1;
	(seg_tree[now]=add(now<<1,l,mid,a,b)+add((now<<1)+1,mid,r,a,b));
	return seg_tree[now]+add_tree[now];
}
int query(int now,int l,int r,int a,int b){
	if(r<=b&&l>=a) {
		return seg_tree[now]+add_tree[now]; 
	}
	if(r<=a||l>=b){
		return 0; 
	}
	int mid=(l+r)>>1;
	return query(now<<1,l,mid,a,b)+query((now<<1)+1,mid,r,a,b)+add_tree[now];
}
bool solve(){
	memset(add_tree,0,sizeof(add_tree));
	memset(seg_tree,0,sizeof(seg_tree));
	while(!q.empty()) q.pop();
	sort(each+1,each+1+n,cmp);
//	rb(i,1,n).
//		cout<<each[i].sa<<" "<<each[i].ea<<" "<<each[i].sb<<" "<<each[i].eb<<endl;
	rb(i,1,n){
		if(!q.empty()) 
//		cout<<"now:"<<i<<"___"<<q.top().FIR<<" "<<each[i].ea<<endl;
		while(!q.empty()&&q.top().FIR>each[i].ea){
//			cout<<each[q.top().SEC].sb<<"_->"<<each[q.top().SEC].eb<<endl;
			add(1,1,treen+1,each[q.top().SEC].sb,each[q.top().SEC].eb+1);
			q.pop();
		}
//		cout<<each[i].sb<<"_->"<<each[i].eb<<endl;
		if(query(1,1,treen+1,each[i].sb,each[i].eb+1)){
			return 0;
		}
		q.push(II(each[i].sa,i));
	}
	return 1;
}
int main(){
	fastio;
	cin>>n;
	map<int,int> M;
	rb(i,1,n){
		cin>>each[i].sa>>each[i].ea>>each[i].sb>>each[i].eb;
		M[each[i].sa]=M[each[i].ea]=M[each[i].sb]=M[each[i].eb]=1;
	}
	int tot=0;
	for(map<int,int> :: IT ite=M.begin();ite!=M.end();ite++){
		ite->SEC=++tot;
	}
	treen=1<<int(ceil(log2(double(tot))));
	treen<<=1;
//	add(1,1,treen+1,5,11);
//	cout<<query(1,1,treen+1,1,7);
//	return 0;
	rb(i,1,n)
		each[i].ea=M[each[i].ea],each[i].eb=M[each[i].eb],each[i].sb=M[each[i].sb],each[i].sa=M[each[i].sa];
	int res=solve();
	rb(i,1,n)
		swap(each[i].sa,each[i].sb),swap(each[i].eb,each[i].ea);
	res&=solve();
	cout<<(res? "YES\n":"NO\n");
	return 0;
}