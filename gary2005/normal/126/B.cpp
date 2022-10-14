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
const int MAXN=2e6+233;
int len=0;
int z[MAXN];
void exkmp(string s){
	z[0]=0;
	for(int i=1,l=0,r=-1;i<s.length();++i){
		if(r>=i&&z[i-l]<r-i+1){
			z[i]=z[i-l];
		}
		else{
			z[i]=max(0,r-i+1);
			check_max(r,i-1);
			int tmp=r;
			while(tmp+1!=s.length()&&s[z[i]]==s[tmp+1]){
				++z[i];
				++tmp;
			}
		}
		if(z[i]+i-1>r){
			r=z[i]+i-1;
			l=i;
		}
	}
}
string s;
int main(){
	cin>>s;
	exkmp(s);
	rb(i,0,s.length()-1){
		check_max(len,z[i]-(i+z[i]-1==s.length()-1));
	}
	int rest=0;
	rb(i,0,s.length()-1){
		if(i+z[i]-1==s.length()-1&&z[i]<=len){
			check_max(rest,z[i]);
		}
	}
	if(rest==0) puts("Just a legend");
	else rb(i,1,rest) cout<<s[i-1];
	return 0;
}