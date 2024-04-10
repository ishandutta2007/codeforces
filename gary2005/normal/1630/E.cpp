/**
 *    author:  gary
 *    created: 27.01.2022 23:47:40
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
namespace combination
{
    const int MOD=998244353;
    const int MAXN=1000000;
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        // cout<<fact[MAXN]<<endl;
        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
} // namespace combination
using namespace combination;
const int bound=1000000;
LL p[bound+1];
int m[bound+1];
bool v[bound+1];
int pri[bound+1];
vector<int> factor[bound+1];
void xxs(){
	int tot=0;
	m[1]=p[1]=1;
	rb(i,2,bound){
		if(!v[i]){
			pri[++tot]=i;
			m[i]=-1;	
			p[i]=i-1;
		}
		rb(j,1,tot){
			if(i>bound/pri[j]) break;
			v[i*pri[j]]=1;
			if(i%pri[j]){
				p[i*pri[j]]=p[i]*(pri[j]-1);
				m[i*pri[j]]=-m[i];
			} 
			else{
				p[i*pri[j]]=p[i]*pri[j];
				m[i*pri[j]]=0;
				break;
			}
		}
	}
    rb(i,1,bound){
        m[i]=MOD+m[i];
        m[i]%=MOD;
    }
    rb(i,1,bound/2)
        for(int j=i;j<=bound/2;j+=i) factor[j].PB(i);
}
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int n,c[bound+1];
int cnt;
int sum;
int g=0;
int ans[bound+1];
void solve_cnt(){
    for(auto it:factor[g]){// to it groups
        int z=fact[n/it];
        rb(i,1,n) z=1ll*z*ifact[c[i]/it]%MOD;
        ans[it]=z;
    }
    rb(i,1,g){
        if(g%i==0){
            for(auto it:factor[g/i]){
                if(it!=1)
                add(ans[i],1ll*ans[it*i]*m[it]%MOD);
            }
        }
    }
    rb(i,1,g){
        if(g%i==0){
            add(cnt,1ll*ans[i]*inv(n/i)%MOD);
            // cout<<i<<"__!!"<<1ll*ans[i]*inv(n/i)%MOD<<endl;
        }
    }
}
int A[bound+1],B[bound+1],mx;
void solve_sum_prime(){
    rl(x,g,1){
        if(g%x==0){
            int sum=0;
            int tot=n/x;
            int all=fact[tot];
            rb(i,1,mx){
                all=1ll*all*ifact[c[i]/x]%MOD;
            }
            rb(i,1,mx){
                if(c[i]/x>=2)
                    add(sum,1ll*all*fact[c[i]/x]%MOD*ifact[tot]%MOD*fact[tot-2]%MOD*ifact[c[i]/x-2]%MOD);
            }
            sum=1ll*(all-sum+MOD)%MOD;
            sum=1ll*sum*tot%MOD;
            for(auto it:factor[g/x]){
                if(it!=1)
                sub(sum,1ll*B[it*x]*it%MOD);
            }
            B[x]=sum;
        }
    }
}
int solve_sum(int x){
    // cout<<x<<endl;
    if(A[x]!=-1) return A[x];
    int answer=0;
    solve_sum_prime();
    for(auto it:factor[g/x]){
        add(answer,1ll*B[x*it]*it%MOD*inv(n/it)%MOD);
    }
    return A[x]=answer;
}
void solve(){
    g=0;
    cnt=sum=0;
    cin>>n;
    rb(i,1,n) c[i]=0;
    vector<int> a(n),l;
    rb(i,1,n){
        cin>>a[i-1];
        l.PB(a[i-1]);
    }
    sort(ALL(l));
    l.erase(unique(ALL(l)),l.end());
    rep(i,n) a[i]=lower_bound(ALL(l),a[i])-l.begin()+1,c[a[i]]++;
    mx=l.size();
    rb(i,1,n){
        if(c[i]==n){
            cout<<1<<endl;
            return;
        }
    }
    rb(i,1,n) g=gcd(g,c[i]);
    rb(i,1,g) A[i]=B[i]=-1;
    solve_cnt();
    // exit(0);
    // if(n==997920){
    //     cout<<"!"<<" "<<cnt<<" "<<g<<endl;
    //     exit(0);
    // }
    sum=solve_sum(1);
    cout<<1ll*sum*inv(cnt)%MOD<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    xxs();
    genmath();
    // return 0;
    cin>>t;
    while(t--) solve();
    return 0;
}