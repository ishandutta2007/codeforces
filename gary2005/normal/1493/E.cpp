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
int main(){
	int n;
	cin>>n;
	string l,r;
	cin>>l>>r;
	string s;
	int t=n;
	rep(i,n){
		if(l[i]!=r[i]){
			t=i;
			break;	
		}
		s.PB(r[i]);
	}
	if(t!=n){
		if(t==0){
			rb(i,1,n) s.PB('1');
		}
		else{
			if(r[n-1]=='1') s=r;
			else{
				int cnt=0;
				rl(i,n-2,t+1){
					if(r[i]=='1'){
						cnt++;
					}
				}
				if(cnt){
					s=r,s[n-1]='1';
				}
				else{
					bool ok;
					ok=0;
					rb(i,t+1,n-1) ok|=(l[i]=='0');
					if(!ok) s=r;
					else s=r,s[n-1]='1';
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}