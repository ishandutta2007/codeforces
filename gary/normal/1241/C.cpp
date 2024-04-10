//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int p[200000+10];
int x,a,y,b;
int n;
LL k;
bool check(int X){
	int va,vb,vab;
	va=vb=vab=0;
	rb(i,1,X){
		if(i%a==0&&i%b==0){
			vab++;
		}
		else
		if(i%a==0){
			va++;
		}	
		else 
		if(i%b==0){
			vb++;
		}
	} 
//	cout<<x<<endl;
	LL res=0;
	int ite=1;
	rb(i,1,vab){
//		cout<<"ab"<<" "<<p[ite]<<" "<<(p[ite]/100)<<" "<<(x+y)<<endl;
//		cout<<res<<endl;
		res+=(p[ite++]/100)*(x+y);
	}
	if(x>y){
	rb(i,1,va){
//		cout<<"a"<<p[ite]<<endl;
		res+=(p[ite++]/100)*(x);
	}
	rb(i,1,vb){
		res+=(p[ite++]/100)*(y);
	}	
	}
	else{
	rb(i,1,vb){
		res+=(p[ite++]/100)*(y);
	}
	rb(i,1,va){
		res+=(p[ite++]/100)*(x);
	}
	}
//	cout<<res<<endl;
	return res>=k;
}
bool cmp(int A,int B){
	return A>B;
}
void solve(){
	cin>>n;
	rb(i,1,n) scanf("%d",&p[i]);
	sort(p+1,p+1+n,cmp);
	cin>>x>>a>>y>>b>>k;
	int l=1,r=n;
	if(!check(n)){
		cout<<-1<<endl;
		return;
	}
	while(l<r){
		int mid=(l+r)>>1;
//		cout<<l<<" "<<r<<endl;
		if(!check((l+r)>>1)) l=mid+1;
		else r=mid;
	}
	cout<<l<<endl; 
}
int main(){
	int q;
	cin>>q;
	while(q--){
		solve();
	}
	return 0;
}