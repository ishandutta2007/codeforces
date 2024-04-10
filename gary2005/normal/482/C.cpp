/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
//#define double (long double)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXM=20;
LL bad[1<<MAXM];
double dp[1<<MAXM][2];//dp[mask]mask 
LL change(LL S,int pos){
	return S|(1ll<<(pos-1));
}
LL query(LL S,int pos){
	return S&(1ll<<(pos-1));
}int n,m,BIT;
int cnt[1<<MAXM],cnt_bit[1<<MAXM];
void update(int to,int from){
	dp[to][1]+=dp[from][1]/double(m-cnt_bit[from])*double(cnt[to])/double(cnt[from]);
	dp[to][0]+=dp[from][1]/double(m-cnt_bit[from])*double(cnt[from]-cnt[to])/double(cnt[from]);
}
int main(){
//	fastio;
	cin>>n;
	if(n==1){
		cout<<"0.0000000000000000"<<endl;
		return 0;
	}
	string s[55];
	rb(i,1,n){
		cin>>s[i];
		s[i]='$'+s[i];
	}
	m=s[n].length()-1;
	BIT=1<<m;
	BIT--;
	rb(i,0,BIT){
		int tmp=i;
		while(tmp){
			cnt_bit[i]+=bool(tmp&1);
			tmp>>=1;
		} 
	} 
	rb(i,1,n){
		rb(j,1,n)
		{
			LL DIff=0ll;
			if(j==i) continue;
			rb(k,1,m){
				if(s[i][k]==s[j][k]){
					DIff=change(DIff,k);
				}
			}
			bad[DIff]=change(bad[DIff],i);
			bad[DIff]=change(bad[DIff],j);
		}
	}
	rl(i,BIT,1){
		rb(j,1,m){
			if(query(i,j)){
				bad[i-(1<<(j-1))]|=bad[i];
			}	
		}
	}
	bad[0]=(1ll<<n)-1;
	rb(i,0,BIT){
		rb(j,1,n){
			if(query(bad[i],j)){
				cnt[i]++;
			}
		}
	}
//	rb(i,0,BIT)
//	{
//		cout<<i<<" "<<cnt[i]<<endl;
//	}
	dp[0][0]=0.0;
	dp[0][1]=1.0;
//	cout<<BIT<<endl;
	rb(mask,1,BIT){
		rep(j,m){
			if(mask&(1<<j)){
				int newmask=mask^(1<<j);
				if(dp[newmask][1]>0.0)
				update(mask,newmask);
			}
		}
	}
	double res=0;
	rb(i,1,BIT){
		res+=(double)cnt_bit[i]*dp[i][0];
	}
	printf("%.17f\n",res);
	return 0;
}