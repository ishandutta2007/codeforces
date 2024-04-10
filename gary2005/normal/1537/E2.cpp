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

const int MAXLEN=5e5+20+5e5; 
int lcp[MAXLEN],Rank[MAXLEN],sa[MAXLEN];
mp Data[MAXLEN];
bool cmp(int A,int B){
	return Data[A]<Data[B];
}
void SA(string s){
	int len=s.length();
	s='$'+s;
	rb(i,1,len)
		Rank[i]=s[i];
	vector<int> order;
	rb(i,1,len)
		order.PB(i);
	rb(j,0,14){
		rb(i,1,len)
			Data[i]=II(Rank[i],i+(1<<j)<=len? Rank[i+(1<<j)]:-1);
		sort(ALL(order),cmp);
		rep(i,order.size())
			Rank[order[i]]=(i==0? 1:Rank[order[i-1]]+(Data[order[i]]!=Data[order[i-1]]));
	}
	rb(i,1,len)
		sa[Rank[i]]=i;
}
int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	SA(s+s);
	string ans;
	rb(i,1,n){
		if(Rank[1]<Rank[i]){
			rb(j,1,i-1){
				ans.PB(s[j-1]);
			}
			break;
		}
	}
	if(ans.empty()) ans=s;
	while(ans.length()<k){
		ans=ans+ans;
	}
	rep(i,k)
	cout<<ans[i];
	return 0;
}