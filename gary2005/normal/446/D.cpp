/**
 *    author:  gary
 *    created: 13.05.2022 18:19:51
**/
#include<bits/stdc++.h>
#define double long double
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
const double eps=1e-7;
const int MAXN=505;
vector<double> nom[MAXN],spe[MAXN];
int n,m,k,c[MAXN],id[MAXN],cnt,is[MAXN];
vector<int> g[MAXN];
struct Matrix{
	vector<vector<double> > mat;
    Matrix(int n){
        mat.assign(n,vector<double>(n,0));
    }
};
Matrix multiplication(Matrix A,Matrix B){
    Matrix C(A.mat.size());
    rep(i,A.mat.size()) rep(j,A.mat.size()) rep(k,A.mat.size()) C.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
    return C;
}
Matrix quick_pow(Matrix A,LL times){
	if(times==0){
		Matrix res(A.mat.size());	
		rb(i,1,A.mat.size()){
			res.mat[i-1][i-1]=1;
		}
		return res;
	}
	Matrix res=quick_pow(A,times>>1);
	res=multiplication(res,res);
	if(times&1) res=multiplication(res,A);
	return res;
}
double f[MAXN][MAXN];
void el(vector<double> &A,vector<double> &B,double C){
    rep(i,A.size()) A[i]-=B[i]*C;
}
struct Basis{
    int n;
    vector<double> V[MAXN];
    bool have[MAXN];
    void init(int N){
        n=N;
        rep(i,n) V[i].clear(),have[i]=0;
    }
    void insert(vector<double> A){
        while (true){
            bool ok=0;
            rep(i,n){
                if(have[i]&&abs(A[i])>eps){
                    ok=1;
                    el(A,V[i],A[i]/V[i][i]);
                }
            }
            if(!ok) break;
        }
        rep(i,n){
            if(abs(A[i])>eps){
                assert(!have[i]);
                double t=A[i];
                rep(j,n+1){
                    A[j]/=t;
                }
                V[i]=A;
                have[i]=1;
                rep(j,n) if(i!=j&&have[j]&&abs(V[j][i])>eps) el(V[j],V[i],V[j][i]/V[i][i]),assert(abs(V[j][i])<eps);
                break;
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    rb(i,1,n) {
        cin>>c[i-1];
        if(c[i-1]==1){
            is[cnt]=i-1;
            id[i-1]=cnt++;
        }
    }
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].PB(v);
        g[v].PB(u);
    }
    rep(i,n) nom[i]=spe[i]=vector<double> (n+1,0);
    rep(i,n){
        if(c[i]==0){
            nom[i][i]=1;
            for(auto it:g[i]) nom[i][it]+=-1.0/g[i].size();
        }
        else{
        spe[i][i]=1;
        spe[i][n]=1;
        nom[i][i]=1;
        nom[i][n]=0; 
        }
    }
    int B=ceil(sqrt(cnt));
    vector<mp> Range;
    for(int l=0;l<cnt;l+=B){
        Range.PB(II(l,min(cnt-1,l+B-1)));
    }
    Basis All;
    Basis INIT;
    INIT.init(n);
    rep(i,n) if(!c[i]) INIT.insert(nom[i]);
    rep(i,cnt){
        // cout<<is[i]<<endl;
        // for(auto it:spe[is[i]]){
        //     cout<<it<<' ';
        // }
        // cout<<endl;
        bool Fir=0;
        for(auto it:Range) if(it.first==i) Fir=1;
        if(Fir){
            All=INIT;
            for(auto it:Range){
                if(it.first!=i){
                    rb(j,it.first,it.second){
                        All.insert(nom[is[j]]);
                    }
                }
            }
        }
        Basis Tmp=All;
        for(auto it:Range){
            if(it.first<=i&&it.second>=i){
                rb(j,it.first,it.second){
                    if(j==i) Tmp.insert(spe[is[i]]);
                    else Tmp.insert(nom[is[j]]);
                }
            }
        }
        // cout<<i<<endl;
        // rep(i,n){
        //     for(auto it:Tmp.V[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        rep(j,n){
            f[j][is[i]]=Tmp.V[j][n];
        }
    }
    // rep(i,n){
    //     rep(j,n){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    Matrix trans(cnt);
    rep(i,n) rep(j,n) if(c[i]&&c[j]){
        for(auto it:g[i]){
            trans.mat[id[i]][id[j]]+=(double)(f[it][j])/(g[i].size());
        }
    }
    trans=quick_pow(trans,k-2);
    double ans=0;
    for(auto it:g[0]) rep(i,n) if(c[i]) {
        // cout<<id[i]<<" "<<cnt-1<<endl;
        ans+=f[it][i]/g[0].size()*trans.mat[id[i]][cnt-1];
    }
    cout<<fixed<<setprecision(16)<<ans<<endl;
    return 0;
}