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
int n;
pair<pair<int,int>,int> a[200000+20]; 
int res[200000+20][2],to[200000+1];
mp Fixed[200000+20];
bool ok=1;
bool check(int index1,int index2){
	return index1<=Fixed[index2].SEC&&index1>=Fixed[index2].FIR;
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n) cin>>a[i].FIR.FIR>>a[i].FIR.SEC,a[i].SEC=i,Fixed[i]=a[i].FIR;
	priority_queue<pair<int,int>,vector<mp>,greater<mp> > q;
	sort(a+1,a+1+n);
	int id=1; 
	rb(is,1,n){
		while(id<=n&&a[id].FIR.FIR==is){
			q.push(II(a[id].FIR.SEC,a[id].SEC));
			id++;
		}
		mp tmp=q.top();
		q.pop();
		res[tmp.SEC][0]=is;
		to[is]=tmp.SEC;
	} 
	set<int> col;
	while(!q.empty()) q.pop();
	id=1;
	set<int> :: IT ite;
	rb(i,1,n){
		while(id<=n&&a[id].FIR.FIR==i){
			id++;
			q.push(II(a[id-1].FIR.SEC,a[id-1].SEC));
			col.insert(res[a[id-1].SEC][0]);
		}
		while(q.top().FIR<i){
			col.erase(res[q.top().SEC][0]);
			q.pop();
		}
		int now=to[i];
		if(check(i,now)){
			
			col.erase(i);
		}
		ite=col.upper_bound(Fixed[to[i]].SEC);
		if(ite!=col.begin()){
			ite--;
			if(*ite>=Fixed[to[i]].FIR){
				rb(j,1,n)
					res[j][1]=res[j][0];
				swap(res[to[i]][1],res[to[*ite]][1]);
				ok=0;
//				cout<<"!"<<endl;			
				break;
			}
		}
		if(check(i,now)){
			
			col.insert(i);
		}
	}
	if(ok){
		cout<<"YES"<<endl;rb(i,1,n) cout<<res[i][0]<<" ";
	}
	else{
		cout<<"NO"<<endl;rb(i,1,n) cout<<res[i][0]<<" ";cout<<endl;rb(i,1,n) cout<<res[i][1]<<" ";
	}
	return 0;
}