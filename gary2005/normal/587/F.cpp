/**
 *    author:  gary
 *    created: 08.06.2022 16:56:38
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
const int MAXN=1e5+20;
int l[MAXN],r[MAXN];
LL answer[MAXN];
vector<pair<mp,int> > queries[MAXN];
string s;
const int MAXLEN=100000+20;
int siz[MAXLEN+MAXLEN];
struct SAM{
    struct state{
        int len,link;
        unordered_map<char,int> ch;
    };
    int sz,last;
    state st[MAXLEN+MAXLEN];
    void sam_init(){
        rep(i,MAXLEN*2) st[i].ch.clear();
        st[0].len=0;
        st[0].link=-1;
        sz=0;
        last=0;
    }
    void sam_extend(char c){
        int cur=++sz;
        st[cur].len=st[last].len+1;
        int p=last;
        while(p!=-1&&st[p].ch.find(c)==st[p].ch.end()){
            st[p].ch[c]=cur;
            p=st[p].link;
        } 
        if(p==-1){
            st[cur].link=0;
        }
        else{
            int q=st[p].ch[c];
            if(st[q].len==st[p].len+1){
                st[cur].link=q;
            }
            else{
                int clone;
                clone=++sz;
                st[clone].len=st[p].len+1;
                st[clone].ch=st[q].ch;
                st[clone].link=st[q].link;
                while(p!=-1&&st[p].ch.find(c)!=st[p].ch.end()&&st[p].ch[c]==q){
                    st[p].ch[c]=clone;
                    p=st[p].link;
                }
                st[cur].link=st[q].link=clone;
            }
        }
        last=cur;
        siz[last]++;
    }
}ds;
LL ans[MAXN];
int n,q;
vector<int> g[MAXLEN+MAXLEN];
bool vis[MAXLEN+MAXLEN];
void calc(int now){
    vis[now]=1;
    for(auto it:g[now]) calc(it),siz[now]+=siz[it];
}
void solvebig(int i){
    ds.sam_init();
    memset(vis,0,sizeof(vis));
    memset(siz,0,sizeof(siz));
    rep(i,MAXLEN*2) g[i].clear();
    rb(j,l[i],r[i]){
        ds.sam_extend(s[j]);
    }
    rb(i,1,ds.sz) g[ds.st[i].link].PB(i);
    calc(0);
    memset(ans,0,sizeof(ans));
    // rl(i,ds.sz,1) {siz[ds.st[i].link]+=siz[i];}
    rb(j,1,n){
        int now=0;
        rb(k,l[j],r[j]){
            if(ds.st[now].ch.find(s[k])==ds.st[now].ch.end()){
                now=-1;
                break;
            }
            now=ds.st[now].ch[s[k]];
        }
        if(now!=-1)
        ans[j]=siz[now];
    }
    rb(j,1,n) ans[j]+=ans[j-1];
    for(auto it:queries[i]) answer[it.second]=ans[it.first.second]-ans[it.first.first-1];
}
vector<pair<mp,int> > query2[MAXN];
struct Trie{
    int ch[MAXN][26],fail[MAXN];
    int cnt;
    vector<int> tree[MAXN];
    vector<int> have[MAXN];
    Trie(){cnt=0;memset(ch,0,sizeof(ch));}
    void insert(int now,int pos,string &s,int id){
        if(pos==s.length()){
            have[now].PB(id);
            return;
        }
        int x=s[pos]-'a';
        if(ch[now][x]==0) ch[now][x]=++cnt;
        insert(ch[now][x],pos+1,s,id);
    }
    void run(){
        queue<int> q;
        rep(i,26) if(ch[0][i]) q.push(ch[0][i]);
        while (!q.empty()){
            int now=q.front();
            q.pop();
            rep(i,26) if(ch[now][i]) fail[ch[now][i]]=ch[fail[now]][i],q.push(ch[now][i]);
            else ch[now][i]=ch[fail[now]][i];
        }
        rb(i,1,cnt) tree[fail[i]].PB(i);
    }
    struct BIT{
        int tree[MAXN];
        BIT(){memset(tree,0,sizeof(tree));}
        void add(int A,int B){
            while (A<MAXN)
            {
                tree[A]+=B;
                A+=A&-A;
            }
        }  
        int query(int A){
            int s=0;
            while (A)
            {
                s+=tree[A];
                A-=A&-A;
            }     
            return s;
        }
    }d;
    void go(int now){
        for(auto it:have[now]){
            // cout<<it<<"+\n";
             d.add(it,1);
        }
        for(auto it:tree[now]) go(it);
        for(auto it:query2[now]){ 
            // cout<<it.second<<" "<<d.query(2)<<" "<<d.query(0)<<endl;
            answer[it.second]+=d.query(it.first.second)-d.query(it.first.first-1);
            // cout<<ans[it.second]<<endl;
        }
        for(auto it:have[now]) {
            // cout<<it<<"-\n";
            d.add(it,-1);
        }
    }
}t;
void solvesmall(int i){
    int now=0;
    rb(j,l[i],r[i]){
        now=t.ch[now][s[j]-'a'];
        for(auto it:queries[i]) query2[now].PB(it);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n){
        string str;
        cin>>str;
        l[i]=s.length()+1;
        r[i]=s.length()+str.length();
        s+=str;
    }
    s="$"+s;
    int SQRTN=ceil(sqrt(s.length()/17.0));
    rb(i,1,n){
        if(r[i]-l[i]<SQRTN){
        string str;
        rb(j,l[i],r[i]) 
        str.PB(s[j]);
        t.insert(0,0,str,i);
        }
    }
    t.run();
    rb(i,1,q){
        int l,r,k;
        cin>>l>>r>>k;
        queries[k].PB(II(II(l,r),i));
    }
    
    rb(i,1,n) if(r[i]-l[i]>=SQRTN){
        solvebig(i);
    }
    else{
        solvesmall(i);
    }
    t.go(0);
    rb(i,1,q) cout<<answer[i]<<'\n';
    return 0;
}