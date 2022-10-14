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
int sum[2][100000+20];
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int x,y;
	cin>>x>>y;
	LL rest=0;
	vector<int> pos;
	rb(i,1,n){
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		if(s[i-1]!='?'){
			if(s[i-1]=='0'){
				rest+=1ll*sum[1][i]*y;
			}
			else{
				rest+=1ll*sum[0][i]*x;
			}
			sum[s[i-1]-'0'][i]++;
		}
		else{
			pos.PB(i);
		}
	}
	LL tmp=0;
		for(auto it:pos){
			tmp+=1ll*(sum[1][n]-sum[1][it])*x+1ll*(sum[1][it])*y;
		} 
	if(x>y){
		//1
		LL tmptmp=tmp;
		rep(i,pos.size()){
			tmp-=1ll*(sum[1][pos[i]]+i)*y;
			tmp-=1ll*(sum[1][n]-sum[1][pos[i]])*x;
			tmp+=1ll*(sum[0][n]-sum[0][pos[i]]+pos.size()-i-1)*y;
			tmp+=1ll*(sum[0][pos[i]])*x;
			check_min(tmptmp,tmp);
		}
		rest+=tmptmp;
	}
	else{
		//1
		LL tmptmp=tmp;
		if(pos.size())
			rl(i,pos.size()-1,0){
				tmp-=1ll*(sum[1][n]-sum[1][pos[i]]+pos.size()-i-1)*x;
				tmp-=1ll*(sum[1][pos[i]])*y;
				tmp+=1ll*(sum[0][n]-sum[0][pos[i]])*y;
				tmp+=1ll*(sum[0][pos[i]]+i)*x;
				check_min(tmptmp,tmp);
			}
		rest+=tmptmp;
	}
	cout<<rest<<endl;
	return 0;
}