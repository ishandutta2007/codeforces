/**
 *    author:  gary
 *    created: 24.12.2021 18:12:16
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e6+23;
int z[MAXN];
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
const int MOD=998244353;
string a,l,r;
int dp[MAXN];
bool geq[MAXN],leq[MAXN];
int pre[MAXN];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>l>>r;
    dp[0]=1;
    z_function(l+"#"+a);
    rb(i_,1,a.length()){
        int i=l.length()+1+i_;
        int j=i_+z[i]-1;
        if(j==a.length()||z[i]==l.length()) geq[i_]=1;
        else geq[i_]=a[j]>l[z[i]];
    }
    z_function(r+"#"+a);
    rb(i_,1,a.length()){
        int i=r.length()+1+i_;
        int j=i_+z[i]-1;
        if(j==a.length()||z[i]==r.length()) leq[i_]=1;
        else leq[i_]=a[j]<r[z[i]];
    }
    dp[0]=pre[0]=1;
    rb(i,1,a.length()){
        pre[i]=pre[i-1];
        if(l.length()+1<r.length()){
            int L,R;
            L=l.length()+1;
            R=r.length()-1;
            check_min(R,i);
            if(L<=R){
                dp[i]=pre[i-L];
                if(R!=i){
                    add(dp[i],MOD-pre[i-R-1]);
                }
            }
        }
        if(l.length()==r.length()){
            if(i>=l.length()){
                if(l.length()==1||a[i-l.length()]!='0'){
                    if(geq[i-l.length()+1]&&leq[i-l.length()+1])
                    add(dp[i],dp[i-l.length()]);
                }
            }
        }
        else{
            if(i>=l.length()){
                if(l.length()==1||a[i-l.length()]!='0'){
                    if(geq[i-l.length()+1])
                        add(dp[i],dp[i-l.length()]);
                }
            }
            if(i>=r.length()){
                if(r.length()==1||a[i-r.length()]!='0'){
                    if(leq[i-r.length()+1])
                        add(dp[i],dp[i-r.length()]);
                }
            }
        }
        if(i!=a.length()&&a[i]!='0') add(pre[i],dp[i]);
    }
    cout<<dp[a.length()]<<endl;
    return 0;
}