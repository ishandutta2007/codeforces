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
int have[100];
int need[100];
int main(){
	int n;
	LL t;
	cin>>n>>t;
	string s;
	cin>>s;
	t-=(1<<(s[n-1]-'a'));
	t+=(1<<(s[n-2]-'a'));
	LL sum=0;
	rb(i,0,n-3) sum=sum+(1<<(s[i]-'a'));
	t+=sum;
	if(t%2==1||t<0){
		puts("No");
		return 0;
	}
	t/=2;
	rb(i,0,n-3) have[s[i]-'a']++;
	rep(i,60) need[i]=(t>>i)&1;
	rep(i,60){
		if(need[i]&&!have[i]){
			puts("No");
			return 0;
		}
		if(need[i]) have[i]--;
		have[i+1]+=have[i]/2;
	}
	puts("Yes");
	return 0;
}