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
int n;
LL t;
LL a[200000+20];
map<LL,int> ls;
int BIT[200000+20];
	int Cnt=0;
int get(int i){
//	cout<<"?"<<i<<endl;
	int sUm=0;
	while(i>0){
		sUm+=BIT[i];
		i-=i & -i;
	}
//	cout<<sUm<<endl;
	return sUm;
}
void change(int i){
//	cout<<"add"<<i<<endl;
	while(i<=Cnt){
		BIT[i]+=1;
		i+= i & -i; 
	}
}
int main(){
	fastio;
	cin>>n>>t;
	rb(i,1,n)
		cin>>a[i];
	LL sum=0;
	vector<LL> s;
	s.PB(0);
	LL ss[200000+20];
	rb(i,1,n){
		sum+=a[i];
		s.PB(sum);
		ss[i]=sum;
//		cout<<"!"<<sum<<endl;; 
	}	
	sort(ALL(s));
	rb(i,1,n+1){
		if(ls[s[i-1]]) continue;
		ls[s[i-1]]=++Cnt;
	}
	LL res=0;
	LL add=0;
	change(ls[0]);
	rb(i,1,n){
//		cout<<i<<endl;
		if(lower_bound(ALL(s),ss[i]-t+1)!=s.end())
		res+=get(Cnt)-get(ls[*lower_bound(ALL(s),ss[i]-t+1)]-1);
//		cout<<res<<endl;
//		cout<<ss[i]-t+1<<"oooo"<<get(Cnt)-get(ls[*lower_bound(ALL(s),ss[i]-t)]-1)<<endl;
		change(ls[ss[i]]);
	}
	cout<<res<<endl;
	return 0;
}