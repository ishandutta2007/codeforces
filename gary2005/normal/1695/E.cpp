/**
 *    author:  gary
 *    created: 18.06.2022 22:28:22
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
const int MAXN=600000+233;
vector<int> g[MAXN];
int ans[2][MAXN];
char s1[2][MAXN];
char s2[2][MAXN];
int n;
vector<mp> ret;
bool vis[MAXN];
int depth[MAXN];
void dfs(int now,int pre){
    vis[now]=1;
    for(auto it:g[now]){
        if(it==pre){
            pre=-1;
            continue;
        }
        if(vis[it]){
            if(depth[it]<=depth[now]){ret.PB(II(now,it));
            ret.PB(II(it,now));}
        }
        else{
            ret.PB(II(now,it));
            depth[it]=depth[now]+1;
            dfs(it,now);
            ret.PB(II(it,now));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int N=n<<1;
    rb(i,1,n){
        int x,y;
        cin>>x>>y;
        g[x].PB(y);
        if(x!=y)
        g[y].PB(x);
    }
    vector<vector<mp> > Dominoes;
    int sum=0;
    rb(i,1,N){
        if(!vis[i]){
            ret.clear();
            dfs(i,0);
            Dominoes.PB({});
            for(int i=0;i<ret.size();i+=2){
                auto it=ret[i];
                if(it.first<=N) Dominoes.back().emplace_back(it.first,it.second);
            }
            // cout<<ret.size()<<endl;
            sum+=Dominoes.back().size();
            if(Dominoes.back().size()==1){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    cout<<2<<' '<<n<<'\n';
    int Alr=0;
    for(auto it:Dominoes){
        // cout<<"!"<<" "<<it.<<endl;
        // for(auto it2:it){
            // cout<<"__"<<it2.first<<" "<<it2.second<<endl;
        // }
        if(it.empty()) continue;
        if(it.size()%2==0){
            int Len=it.size()/2;
            rep(i,Len){
                ans[0][Alr+1+i*2]=it[i].first;
                ans[0][Alr+2+i*2]=it[i].second;
                ans[1][Alr+1+i*2]=it[i+Len].first;
                ans[1][Alr+2+i*2]=it[i+Len].second;
            }
            reverse(ans[1]+Alr+1,ans[1]+Alr+Len*2+1);
            rb(i,1,Len*2) s1[0][i+Alr]=s1[1][i+Alr]=(i&1? 'L':'R');
            rb(i,1,Len*2) s2[0][i+Alr]=s2[1][i+Alr]=(i&1? 'R':'L');
            s2[0][Alr+1]=s2[0][Alr+Len*2]='U';
            s2[1][Alr+1]=s2[1][Alr+Len*2]='D';
            Alr+=Len*2;
        }
        else{
            // cout<<it.size()<<endl;
            vector<mp> Tmp;
            mp Mid;
            rep(i,it.size()){
                if(i==it.size()/2){
                    Mid=it[i];
                    continue;
                }
                Tmp.PB(it[i]);
            }
            it.swap(Tmp);
            int Len=it.size()/2;
            rep(i,Len){
                ans[0][Alr+1+i*2]=it[i].first;
                ans[0][Alr+2+i*2]=it[i].second;
                ans[1][Alr+1+i*2]=it[i+Len].first;
                ans[1][Alr+2+i*2]=it[i+Len].second;
            }
            reverse(ans[1]+Alr+1,ans[1]+Alr+Len*2+1);
            ans[0][Alr+2*Len+1]=Mid.first;
            ans[1][Alr+2*Len+1]=Mid.second;
            rb(i,1,Len*2+1) s1[0][i+Alr]=s1[1][i+Alr]=(i&1? 'L':'R');
            rb(i,1,Len*2+1) s2[0][i+Alr]=s2[1][i+Alr]=(i&1? 'R':'L');
            s1[0][Alr+1+Len*2]='U',s1[1][Alr+1+Len*2]='D';
            s2[0][Alr+1]='U',s2[1][Alr+1]='D';
            Alr+=Len*2+1;
        }
    }
    cout<<endl;
    rep(i,2) {rb(j,1,n) cout<<ans[i][j]<<' ';cout<<endl;}
    cout<<endl;
    rep(i,2) {rb(j,1,n) cout<<s1[i][j];cout<<endl;}
    cout<<endl;
    rep(i,2) {rb(j,1,n) cout<<s2[i][j];cout<<endl;}
    cout<<endl;
    return 0;
}