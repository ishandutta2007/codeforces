/*
Solution From WSR
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
int treen,t,n,tot,a[1000000],res[1000000];
mp seg[200000+10]; 
map<int,int> lisan;
void mian(){
	memset(a,0,sizeof(a));
	lisan.clear();
	tot=0;
	cin>>n;
	rb(i,1,n){
		cin>>seg[i].FIR>>seg[i].SEC;
		lisan[seg[i].FIR]=lisan[seg[i].SEC]=1;
	}
	for(map<int,int> :: IT ite=lisan.begin();ite!=lisan.end();ite++){
		ite->SEC=++tot;
	}
	int MAX=-1;
	rb(i,1,n){
		seg[i].FIR=lisan[seg[i].FIR]*2;
		seg[i].SEC=lisan[seg[i].SEC]*2;
//		cout<<seg[i].FIR<<"  "<<seg[i].SEC<<endl; 
//		cout<<seg[i].FIR<<" "<<seg[i].SEC<<endl;
		MAX=max(MAX,max(seg[i].FIR,seg[i].SEC)) ;
	}MAX++;
	rb(i,1,MAX)
		res[i]=a[i]=0;
	sort(seg+1,seg+1+n);
	int OK=0;
	rb(i,2,n){
		if(seg[i-1].SEC>=seg[i].FIR){
			OK=1;
			break;
		}
	}
	if(!OK){
		cout<<n-1<<endl;
		return ;
	}
	rb(i,1,n){
		a[seg[i].FIR]++;
		a[seg[i].SEC+1]--;
	}
	int res_=0;
	rb(i,1,MAX)
		a[i]+=a[i-1];
	rb(i,1,MAX){
		if(a[i]==0&&a[i-1]){
			res_++;
		}
		if(a[i]==1&&a[i-1]>1&&a[i+1]>1){
//			cout<<i<<endl;
			res[i]++;
		}
	}
	int add=0;
	rb(i,1,MAX){
		res[i]+=res[i-1];
	}
	rb(i,1,n)
	{
		add=max(add,res[seg[i].SEC]-res[seg[i].FIR-1]);
	}
	cout<<res_+add<<endl;
}
int main(){
	fastio;
	cin>>t;
	while(t--) mian();
	return 0;
}