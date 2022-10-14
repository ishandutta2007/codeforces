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
int n;
vector<int> s,t;
int bestpre[200000+20],bestsuf[200000+20];
void solve()
{
	scanf("%d",&n);
	s.resize(n);
	rep(i,n)
		scanf("%d",&s[i]);
	t.clear();
	rl(i,2*n,1)
		if(lower_bound(ALL(s),i)==s.end()||*lower_bound(ALL(s),i)!=i) t.PB(i);
	bestpre[0]=INF;
	int z=n-1;
	rb(i,1,n){
		while(z>=0&&t[z]<s[i-1]) --z;
//		cout<<i<<' '<<z<<' '<<t[z]<<endl; 
		bestpre[i]=min(bestpre[i-1],i-1+z+1);
	}
	bestsuf[n+1]=-INF;
	z=0;
	rl(i,n,1){
		while(z<n&&t[z]>s[i-1]) ++z;
		bestsuf[i]=max(bestsuf[i+1],z+1-(n-i));
	}
	int rest=0;
	rb(i,0,n){
		if(bestpre[i]>=i&&bestsuf[i+1]<=i+1){
//			cout<<i<<' '<<bestpre[i]<<' '<<bestsuf[i+1]<<endl;
			rest++;	
		} 
	}
	printf("%d\n",rest); 
}
int main(){
int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}