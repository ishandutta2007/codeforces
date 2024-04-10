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
int ans[1<<18];
int main(){
	int k;
	scanf("%d",&k);
	string s;
	cin>>s;
	reverse(ALL(s));
	s="1"+s;
	rb(i,(1<<(k-1)),(1<<(k))-1){
		if(s[i]=='?') ans[i]=2;
		else ans[i]=1;
	}
	rl(i,(1<<(k-1))-1,1){
		if(s[i]=='1') ans[i]=ans[i<<1];
		else if(s[i]=='0')ans[i]=ans[i<<1|1];
		else ans[i]=ans[i<<1]+ans[i<<1|1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int p;
		char c;
		cin>>p>>c;
		p=(1<<k)-p;
		s[p]=c;
		while(p){
			if(p>=(1<<(k-1))){
				ans[p]=1+(s[p]=='?');
			}
			else{
				int i=p;
				if(s[i]=='1') ans[i]=ans[i<<1];
				else if(s[i]=='0')ans[i]=ans[i<<1|1];
				else ans[i]=ans[i<<1]+ans[i<<1|1];
			}
			p>>=1;
		}
		printf("%d\n",ans[1]);
	}
	return 0;
}