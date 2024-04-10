/**
 *    author:  gary
 *    created: 09.11.2021 20:53:44
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
const int bound=100000;
int p[bound+1];
int m[bound+1];
bool v[bound+1];
int pri[bound+1];
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
}
vector<mp> sqrtdivide(int x){
    // return the segment [li,ri],where x/li = x/ri 
    // in O (x^(0.5))
    vector<mp> ans;
    int sqt=1;
    for(int i=1;i*i<=x;i++){
        sqt=i;
        ans.PB(II(i,i));
    }
    rl(i,sqt,1){
        int l,r;
        r=x/i;
        l=ceil(x/(i+1)+1e-9);
        check_max(l,sqt+1);
        if(l<=r)
        ans.PB(II(l,r));
    }
    return ans;
}
LL pre[bound+1];
pair<mp,LL> prefixsum[bound+1][640];
int siz[bound+1];
LL c(int l,int r){
    LL ans=r-l+1;
    auto Tmp=lower_bound(prefixsum[r],prefixsum[r]+siz[r],II(II(l,INF),(LL)(1e18)));
    Tmp=prev(Tmp);
    ans+=prefixsum[r][siz[r]-1].SEC;
    ans-=Tmp->SEC;
    int R=Tmp->FIR.SEC;
    ans+=1ll*pre[r/Tmp->FIR.FIR]*(R-l+1);
    return ans;
}
LL dp[100000+10][30];
void trans(int a,int b,int l,int r,int j){
    if(a>b) return ;
    int mid=(a+b)/2;
    int p=1;
    LL val=1e18;
    rb(i,l,min(r,mid)){
        LL tmp=c(i,mid)+dp[i-1][j-1];
        if(tmp<val){
            tie(p,val)=II(i,tmp);
        }
    }
    dp[mid][j]=val;
    trans(a,mid-1,l,p,j);
    trans(mid+1,b,p,r,j);
}
int main(){
    xxs();
    p[1]=0;
    rb(i,1,bound) pre[i]=pre[i-1]+p[i];
    rb(i,1,bound){
        auto tmp=sqrtdivide(i);
        siz[i]=tmp.size();
        rep(j,tmp.size()){
            LL val=0;
            if(j) val=prefixsum[i][j-1].SEC;
            val+=1ll*(tmp[j].SEC-tmp[j].FIR+1)*pre[i/tmp[j].FIR];
            prefixsum[i][j]=II(tmp[j],val);
        }
    }
    rb(i,0,100000) rb(j,1,29) dp[i][j]=1e18;
    rb(i,1,100000) dp[i][1]=c(1,i);
    rb(j,2,29) trans(1,100000,1,100000,j);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(k>=30){
            printf("%d\n",n);
        }
        else{
            printf("%lld\n",dp[n][k]);
        }
    }
    return 0;
}