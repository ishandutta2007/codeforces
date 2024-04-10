#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205

const int MAX_N = 200000 +10;
struct Node{
    static Node mem[MAX_N<<1],*pmem;
    Node *ch[26],*fail;
    int mx,val;
    LL dp,cnt;
    int tag,deg,dep;
    Node():mx(0),fail(0),dp(0),val(0),tag(0),deg(0),cnt(0),dep(0){
        for(int i = 0;i<26;i++)ch[i]=NULL;
    }
}Node::mem[MAX_N<<1],*Node::pmem=Node::mem,*root,*last;
int T,N;
char s[MAX_N];
void init(){
    Node::pmem=Node::mem;
    last=root=new (Node::pmem++)Node();
}
int idx(char c){
    return c-'a';
}
void insert(char c){
    c=idx(c);
    Node *p=last;
    Node *np=new (Node::pmem++)Node();
    np->mx=p->mx+1;
    np->val=1;
    while(p &&!p->ch[c]){
        p->ch[c]=np;
        np->deg++;
        p=p->fail;
    }
    if(!p)np->fail=root;
    else{
        Node *q=p->ch[c];
        if(q->mx==p->mx+1)np->fail=q;
        else{
            Node *nq=new (Node::pmem++)Node();
            nq->mx=p->mx+1;
            nq->val=0;
            memcpy(nq->ch,q->ch,sizeof(q->ch));
            for(int i = 0;i<26;i++)
                if(nq->ch[i])
                    nq->ch[i]->deg++;
            nq->fail=q->fail;
            q->fail=np->fail=nq;
            while(p&&p->ch[c]==q){
                p->ch[c]=nq;
                q->deg--;
                nq->deg++;
                p=p->fail;
            }
        }
    }
    last=np;
}
LL ans;
bool cmp(Node *p,Node *q){
    return p->dep>q->dep;
}
void BFS(){
    queue<Node*> q;
    q.push(root);
    root->cnt=1;
    vector<Node*> v;
    while(!q.empty()){
        Node *n=q.front();
        q.pop();
        v.pb(n);
      /*  if(n!=root){
            ans+=n->cnt*n->dp*n->dp;
        }*/
        for(int i = 0;i<26;i++){
            if(n->ch[i]){
                n->ch[i]->cnt+=n->cnt;
                n->ch[i]->dep=max(n->ch[i]->dep,n->dep+1);
                if(--n->ch[i]->deg==0){
                    q.push(n->ch[i]);
                }
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v){
        it->dp+=it->val;
        if(it!=root)
        ans+=it->dp*it->dp*it->cnt;
        //printf("%lld %lld %d\n",it->dp,it->cnt,it-root);
        if(it->fail)
        it->fail->dp+=it->dp;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        ans=0;
        char c[100005];
        /*for(int i = 0;i<5;i++){
            c[i]=rand()%26+'a';
        }*/
       // c[100000]=0;
        scanf("%s",c);
        //printf("%s\n",c);
        for(int i = 0;c[i]!=0;i++){
            insert(c[i]);
        }
       // build();
        BFS();
        printf("%lld\n",ans);
       /* LL sum=0;
        map<string,int> m;
        for(int i = 0;i<5;i++){
            for(int j=i;j<5;j++){
                sum+=m[string(c+i,c+j+1)]*2+1;
                m[string(c+i,c+j+1)]++;
              //  printf("%s\n",string(c+i,c+j+1).c_str());
            }
        }
        printf("%lld\n",sum);
        assert(sum==ans);*/
    }
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/