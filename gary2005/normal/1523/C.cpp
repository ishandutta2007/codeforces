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
queue<string> sta[1001];
string tostring(int x){
	string tmp;
	while(x){
		tmp.PB(char('0'+x%10));
		x/=10;
	}
	reverse(ALL(tmp));
	return tmp;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> v;
		rb(i,1,n){
			int ai;
			scanf("%d",&ai);
			if(ai==1){
				v.PB(ai);
			}
			else{
				while(v.back()!=ai-1){
					v.POB();
				}
				v.back()=ai;
			}
			rep(i,v.size()){
				printf("%d",v[i]);
				if(v.size()-1==i);
				else{
					printf(".");
				}
			}
			puts("");
		}
	}
	return 0;
}