/**
 *    author:  gary
 *    created: 11.11.2021 18:25:13
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
const int BOUND=1e6;
SRAND;
struct stringhash{
    int v[BOUND+1];
    int MOD,BASE;
    int pw[BOUND+1],ipw[BOUND+1];
    int val[26];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    stringhash(int P,int B){
        MOD=P;
        BASE=B;
        pw[0]=1;
        rb(i,1,BOUND) pw[i]=1ll*pw[i-1]*B%MOD;
        ipw[BOUND]=inv(pw[BOUND]);
        rl(i,BOUND-1,0) ipw[i]=1ll*B*ipw[i+1]%MOD;
        set<int> vis;
        rep(i,26){
            int tmp=random(B);
            while(vis.find(tmp)!=vis.end()) tmp=random(B);
            vis.insert(tmp);
            val[i]=tmp;
        }
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
    void gen(string s){
        v[0]=0;
        rb(i,1,s.length()){
            v[i]=v[i-1];
            add(v[i],1ll*pw[i]*val[s[i-1]-'a']%MOD);
        }
    }
    int query(int l,int r){
        int tmp=v[r];
        sub(tmp,v[l-1]);
        tmp=1ll*tmp*ipw[l-1]%MOD;
        return tmp;
    }
}hs(1e9+7,97);
int answer[BOUND+1];
int main(){
    string s;
    int n;
    cin>>n;
    cin>>s;
    hs.gen(s);
    int pr=0;
    rl(i,(n+1)/2,1){
        pr+=2;
        int l,r;
        l=i;
        r=n-i+1;
        check_min(pr,r-l);
        while(pr&&(pr%2==0||hs.query(l,l+pr-1)!=hs.query(r-pr+1,r))) pr--;
        if(!pr) 
        answer[i]=-1;
        else
        answer[i]=pr;
    }
    rb(i,1,(n+1)/2){
        printf("%d ",answer[i]);
    }
    return 0;
}