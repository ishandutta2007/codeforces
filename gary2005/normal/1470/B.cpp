/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
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
int n,a[300000+20];
map<int,int> oc;
map<int,int> se;
int s[1000000+20];
bool pr[1000000+20];
void solve(){
	oc.clear();
	se.clear(); 
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),a[i]=s[a[i]],oc[a[i]]++;
	se=oc;
	for(auto ite=oc.begin();ite!=oc.end();ite++){
		if(ite->FIR!=1)
		if((ite->SEC)%2==0){
			se.erase(ite->FIR);
			se[1]+=ite->SEC;
		}
	}
	int d1=1,d2=1;
	for(auto ite=oc.begin();ite!=oc.end();ite++) check_max(d1,ite->SEC);
	for(auto ite=se.begin();ite!=se.end();ite++){
		check_max(d2,ite->SEC);	
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		LL w;
		scanf("%lld",&w);
		if(w>0){
			printf("%d\n",d2);
		}
		else{
			printf("%d\n",d1);
		}
	}
}
bool chk(int num,int z){
	int cnt=0;
	while(num%z==0){
		num/=z;
		cnt++;
	}
	return cnt%2==1;
}
int main(){
	rb(i,1,1000000) s[i]=1;
	rb(i,2,1000000){
		if(!pr[i]){
			s[i]=i;
			for(int j=i+i;j<=1000000;j+=i){
				if(chk(j,i)) s[j]*=i;
				pr[j]=1;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}