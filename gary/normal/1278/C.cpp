/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
*/
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[200000+10],cnt1[200000+10],cnt2[200000+10],mini[200000+10],maxi[200000+10];
void solve(){
	int n;
	scanf("%d ",&n);n=n+n;
	rb(i,0,n) cnt1[i]=cnt2[i]=0,maxi[i]=-INF,mini[i]=INF;
	maxi[n/2]=0;
	mini[n/2]=n+1;
	cnt1[0]=cnt2[n+1]=0;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n/2){
		cnt1[i]=cnt1[i-1];
		if(a[i]==1) cnt1[i]++;//1-2
		else cnt1[i]--;
		maxi[cnt1[i]+n/2]=max(maxi[cnt1[i]+n/2],i);
	}
	rl(i,n,n/2+1){
		cnt2[i]=cnt2[i+1];
		if(a[i]==2) cnt2[i]++;//2-1
		else cnt2[i]--;
		mini[cnt2[i]+n/2]=min(mini[cnt2[i]+n/2],i);
	}
	int res=INF;
	rb(i,0,n){
		res=min(res,mini[i]-maxi[i]-1);
	}
	printf("%d\n",res);
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}