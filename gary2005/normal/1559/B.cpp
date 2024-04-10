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
int n;
char rev(char c){
	if(c=='R') return 'B';
	return 'R';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		string s;
		cin>>s;
		int x=-1;
		rep(i,n){
			if(s[i]!='?'){
				x=i;
				break;
			}
		}
		if(x==-1){
			rep(i,n){
				if(i&1){
					printf("R");
				}
				else{
					printf("B");
				}
			}
			cout<<endl;
			continue;
		}
		char c=s[x];
		c=rev(c);
		string ans=s;
		rl(i,x-1,0){
			ans[i]=c;
			c=rev(c);
		}
		rb(i,x,n-1){
			if(s[i]!='?'){
				c=s[i];
				ans[i]=s[i];
			}
			else{
				c=rev(c);
				ans[i]=c;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}