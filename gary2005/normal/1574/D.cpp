/**
 *    author:  gary
 *    created: 20.09.2021 22:34:43
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
int n;
int a[11][200000+1];
int c[11];
bool vis[11][200000+1];
pair<int,vector<int> >  answer;
vector<int> noww;
const int MOD=(1<<18)-1;
struct HASH_TABLE{
	int tp[MOD];
	vector<int> nex,val;
	vector<vector<int> > is;
	HASH_TABLE(){
		fill(tp,tp+MOD,-1);
	}
    int see(vector<int> &v){
        unsigned int se=0;
        for(auto it:v){
            se^=it;
            se^=se<<7;
            se^=se>>3;
        }
        return se&MOD;
    }
	void insert(vector<int> p,int v){
		int se=see(p);
		se&=MOD;
		nex.PB(tp[se]);
		tp[se]=nex.size()-1;
		val.PB(v);
		is.PB(p);
	}
	int query(vector<int> p){
		int se=see(p);
		se&=MOD;
		for(int now=tp[se];now!=-1;now=nex[now]){
			if(is[now]==p) return val[now];
		}
		return -1;
	}
}hs;
bool dfs(int now,int tot=1,int tot2=0){
    if(now==n+1){
        if(hs.query(noww)!=-1) return false;
        check_max(answer,II(tot2,noww));
        return true;
    }
    rb(j,1,min(c[now],100001/tot)){
        noww.PB(j);
        bool ok=dfs(now+1,tot*j,tot2+a[now][j]);
        noww.POB();
        if(!vis[now][j]||ok){
            if(ok&&j==1) return 1;
            return 0;
        }
    }
    return 0;
}
int main(){
    cin>>n;
    rb(i,1,n){
        cin>>c[i];
        rb(j,1,c[i]){
            scanf("%d",&a[i][c[i]-j+1]);
        }
    }
    int m;
    cin>>m;
    vector<int> v(n);
    rb(i,1,m){
        rep(j,n) scanf("%d",&v[j]),v[j]=c[j+1]-v[j]+1,vis[j+1][v[j]]=1;
        hs.insert(v,1);
    }
    answer.FIR=-INF;
    dfs(1);
    rep(j,n){
        printf("%d ",c[j+1]-answer.SEC[j]+1);
    }
    cout<<endl;
    return 0;
}