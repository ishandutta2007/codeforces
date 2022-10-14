/**
 *    author:  gary
 *    created: 14.11.2021 14:01:26
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
const int MAXN=10;
string s[MAXN];
int n;
int nex[MAXN][52][2][52];
int getid(char c){
    if(c<='z'&&c>='a') return c-'a';
    return c-'A'+26;
}
char getc(int id){
    if(id<26) return 'a'+id;
    return 'A'+(id-26);
}
int a[MAXN][500],is[MAXN][500];
int dp[52][1<<MAXN];
mp las[52][1<<MAXN];
vector<pair<short,short> > g[52][1<<MAXN];
int cnt[52][1<<MAXN];
bool have[52];
bool vis[52][1<<MAXN];
void fuck(int i,int mask){
    vis[i][mask]=1;
    for(auto it:g[i][mask]){
        if(!vis[it.FIR][it.SEC]) fuck(it.FIR,it.SEC);
    }
}
void solve(){
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    rep(i,n) cin>>s[i];
    rep(i,n){
        bool ok=0;
        rep(j,i){
            if(s[j]==s[i]) ok=1;
        }
        if(ok){
            swap(s[i],s[n-1]);
            --n;
            --i;
        }
    }
    rep(i,52) have[i]=1;
    rep(i,n){
        rep(c,52) rep(nexc,52) rep(j,2) nex[i][c][j][nexc]=3;
        bool vis[52];
        memset(vis,0,sizeof(vis));
        rep(j,s[i].length()){
            int id=getid(s[i][j]);
            a[i][j]=id;
            if(vis[id]){
                is[i][j]=1;
            }
            else{
                is[i][j]=0;
            }
            vis[id]=1;
        }
        rep(j,52) have[j]&=vis[j];
        rep(k,s[i].length()){
            rep(j,k){
                check_min(nex[i][a[i][j]][is[i][j]][a[i][k]],is[i][k]);
            }
        }
    }
    rep(c,52){
        rep(mask,1<<n){
            g[c][mask].clear();
            rep(nexc,52){
                bool ok=1;
                int nmask=0;
                rep(j,n){
                    if(nex[j][c][(mask>>j)&1][nexc]==3){
                        ok=0;
                        break;
                    }
                    nmask|=nex[j][c][(mask>>j)&1][nexc]<<j;
                }
                if(!ok) continue;
                g[c][mask].PB(II(nexc,nmask));
            }
        }
    }
    memset(dp,-63,sizeof(dp));
    queue<mp> qq;
    bool ok=0;
    rep(c,52){
        if(have[c]){
            if(!vis[c][0])
            fuck(c,0);
            ok=1;
        }
    }
    rep(c,52) rep(mask,1<<n) if(vis[c][mask])for(auto it:g[c][mask]){
        cnt[it.FIR][it.SEC]++;
    }
    rep(c,52){
        if(have[c]&&cnt[c][0]==0){
            dp[c][0]=1;
            qq.push(II(c,0));
        }
    }
    if(!ok){
        cout<<0<<endl<<endl;
        return ;
    }
    mp last=II(-1,-1);
    while(!qq.empty()){
        int i,mask;
        tie(i,mask)=qq.front();
        if(last.FIR==-1||dp[i][mask]>dp[last.FIR][last.SEC]) last=II(i,mask);
        qq.pop();
        for(auto it:g[i][mask]){
            int nexc,nmask;
            tie(nexc,nmask)=it;
            if(dp[nexc][nmask]<dp[i][mask]+1){
                dp[nexc][nmask]=dp[i][mask]+1;
                las[nexc][nmask]=II(i,mask);
            }
            cnt[nexc][nmask]--;
            if(!cnt[nexc][nmask])
            qq.push(II(nexc,nmask));
        }
    }
    string answer;
    int i,mask;
    tie(i,mask)=last;
    while(true){
        answer.PB(getc(i));
        if(dp[i][mask]==1){
            break;
        }
        tie(i,mask)=las[i][mask];
    }
    reverse(ALL(answer));
    cout<<answer.length()<<endl<<answer<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}