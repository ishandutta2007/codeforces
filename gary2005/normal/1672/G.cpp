/**
 *    author:  gary
 *    created: 18.05.2022 18:51:04
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
struct func{
    int x,y;
    func(){x=y=INF;}
    func(int X,int Y){x=X,y=Y;}
    bool in(int t){return t==x||t==y;}
};
func operator ^ (func A,func B){
    func ans;
    vector<int> v;
    if(A.x!=INF&&!B.in(A.x)) v.PB(A.x);
    if(A.y!=INF&&!B.in(A.y)) v.PB(A.y);
    if(B.x!=INF&&!A.in(B.x)) v.PB(B.x);
    if(B.y!=INF&&!A.in(B.y)) v.PB(B.y);
    if(v.size()>1&&v[0]>v[1]) swap(v[0],v[1]);
    for(auto it:v) {
        if(ans.x==INF) ans.x=it;
        else ans.y=it;
    }
    return ans;
}
const int MOD=998244353;
func v[4000];
int pw2(int x){
    int rest=1;
    rb(i,1,x) rest<<=1,rest%=MOD;
    return rest;
}
bool insert(func f){
    while (f.x!=INF){
        int i=f.x;
        if(v[i].x==INF){
            v[i]=f;
            rep(j,4000) if(j!=i&&(v[i].x==j||v[i].y==j)&&v[j].x!=INF) v[i]=v[i]^v[j];
            rep(j,4000) if(j!=i&&(v[j].x==i||v[j].y==i)) v[j]=v[j]^v[i];
            return true;
        }
        else f=f^v[i];
    }
    return false;
}
bool y[4000];
bool check(){
    rep(i,4000) if(y[i]){
        if(v[i].x!=INF) y[v[i].x]^=1;
        if(v[i].y!=INF) y[v[i].y]^=1;
    }
    if(*max_element(y,y+4000)==1){
        return 0;
    }
    return 1;
}
int cntr[2000],cntc[2000];
int rxor[2000],cxor[2000];
char getc(){
    char c=getchar();
    while (c!='0'&&c!='1'&&c!='?')
    {
        c=getchar();
    }
    return c;
}
int main(){
    // freopen("test.in","r",stdin);
    int r,c;
    cin>>r>>c;
    int ans=0;
    int cnt=0;
    if(r%2==0&&c%2==0){
        rep(i,r) rep(j,c){
            char ch;
            ch=getc();
            if(ch=='?') cnt++;
        }
        cout<<pw2(cnt)<<endl;
        return 0;
    }
    if(r%2!=c%2){
        rep(i,r) rep(j,c){
            char ch;
            ch=getc();
            if(ch=='?') cntr[i]++,cntc[j]++;
            else rxor[i]^=ch-'0',cxor[j]^=ch-'0';
        }
        if(r%2){
            swap(r,c);
            rep(i,r) cntr[i]=cntc[i],rxor[i]=cxor[i];
        }
        bool noans=0;
        rep(i,r) rep(j,r){
            if(!cntr[i]&&!cntr[j]&&rxor[i]!=rxor[j]){
                noans=1;
            }
        }
        if(noans){
            cout<<0<<endl;
            return 0;
        }
        int ans=1;
        rep(i,r){
            if(cntr[i]>0) ans=1ll*ans*pw2(cntr[i]-1)%MOD;
        }
        if(*min_element(cntr,cntr+r)) ans=2ll*ans%MOD;
        cout<<ans<<endl;
        return 0;
    }
    rep(i,r) rep(j,c){
        char ch;
        ch=getc();
        if(ch=='?') cnt+=!insert(func(i,r+j)),cntr[i]++,cntc[j]++;
        else rxor[i]^=ch-'0',cxor[j]^=ch-'0';
    }
    int Temp=pw2(cnt);
    rep(Rt,2) rep(Ct,2){
        memset(y,0,sizeof(y));
        rep(i,r) y[i]=Rt^rxor[i];
        rep(j,c) y[j+r]=Ct^cxor[j];
        if(check()){
            ans+=Temp;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}